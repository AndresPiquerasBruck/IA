# include "AIPlayer.h"
# include "Parchis.h"

const double masinf = 9999999999.0, menosinf = -9999999999.0;
const double gana = masinf - 1, pierde = menosinf + 1;
const int num_pieces = 4;
const int PROFUNDIDAD_MINIMAX = 4;  // Umbral maximo de profundidad para el metodo MiniMax
const int PROFUNDIDAD_ALFABETA = 6; // Umbral maximo de profundidad para la poda Alfa_Beta

bool AIPlayer::move(){
    cout << "Realizo un movimiento automatico" << endl;
    
    color c_piece;
    int id_piece;
    int dice;
    think(c_piece, id_piece, dice);

    cout << "Movimiento elegido: " << str(c_piece) << " " << id_piece << " " << dice << endl;

    actual->movePiece(c_piece, id_piece, dice);
    return true;
}

void AIPlayer::think(color & c_piece, int & id_piece, int & dice) const{

    double valor; // Almacena el valor con el que se etiqueta el estado tras el proceso de busqueda.
    double alpha = menosinf, beta = masinf; // Cotas iniciales de la poda AlfaBeta
    // Llamada a la función para la poda (los parámetros son solo una sugerencia, se pueden modificar).
    valor = Poda_AlfaBeta(*actual, jugador, 0, PROFUNDIDAD_ALFABETA, c_piece, id_piece, dice, alpha, beta, ValoracionMATANINJAS);
    cout << "Valor MiniMax: " << valor << "  Accion: " << str(c_piece) << " " << id_piece << " " << dice << endl;

    // ----------------------------------------------------------------- //

    // Si quiero poder manejar varias heurísticas, puedo usar la variable id del agente para usar una u otra.
    switch(id){
        case 0:
            valor = Poda_AlfaBeta(*actual, jugador, 0, PROFUNDIDAD_ALFABETA, c_piece, id_piece, dice, alpha, beta, ValoracionMATANINJAS);
            break;
        case 1:
            valor = Poda_AlfaBeta(*actual, jugador, 0, PROFUNDIDAD_ALFABETA, c_piece, id_piece, dice, alpha, beta, ValoracionTest);
            break;
    }
    cout << "Valor MiniMax: " << valor << "  Accion: " << str(c_piece) << " " << id_piece << " " << dice << endl;
}

double AIPlayer::Poda_AlfaBeta(const Parchis &actual, int jugador, int profundidad, int profundidad_max, color &c_piece, int &id_piece, int &dice, double alpha, double beta, double (*heuristic)(const Parchis &, int)) const{
    
    double valor;

    if (profundidad == profundidad_max || actual.gameOver()){
        return heuristic(actual, jugador);
    }else{
        color last_c_piece = none;      //El color de la última ficha que se movió
        int last_id_piece = -1;         //El id de la última ficha que se movió.
        int last_dice = -1;             //El dado que se usó en el último movimiento        
        
        Parchis nodohijo = actual.generateNextMoveDescending(last_c_piece, last_id_piece, last_dice);
        double mejor;
        
       if (actual.getCurrentPlayerId() == jugador){   //Si nodo MAX
            while (!(nodohijo == actual)){
            color dummy_c_piece = c_piece;
            int dummy_id_piece = id_piece;
            int dummy_dice = dice;

            valor = Poda_AlfaBeta(nodohijo, jugador, profundidad+1, profundidad_max,dummy_c_piece, dummy_id_piece, dummy_dice, alpha, beta, heuristic);

            if (valor > alpha){
                alpha = valor;
                c_piece = last_c_piece;
                id_piece = last_id_piece;
                dice = last_dice;
            }

            if (beta<=alpha){
                break;
            }

            nodohijo = actual.generateNextMoveDescending(last_c_piece, last_id_piece, last_dice);
            }
            return alpha;
        }else{                                       //Si nodo MIN
            while (!(nodohijo == actual)){
                color dummy_c_piece = c_piece;
                int dummy_id_piece = id_piece;
                int dummy_dice = dice;

                valor = Poda_AlfaBeta(nodohijo, jugador, profundidad+1, profundidad_max,dummy_c_piece, dummy_id_piece, dummy_dice, alpha, beta, heuristic);

                if (valor < beta){
                    beta = valor;
                    c_piece = last_c_piece;
                    id_piece = last_id_piece;
                    dice = last_dice;
                }

                if (beta<=alpha){
                    break;
                }

                nodohijo = actual.generateNextMoveDescending(last_c_piece, last_id_piece, last_dice);
            }
            return beta;
        }
    }
}

double AIPlayer::ValoracionTest(const Parchis &estado, int jugador)
{
    // Heurística de prueba proporcionada para validar el funcionamiento del algoritmo de búsqueda.


    int ganador = estado.getWinner();
    int oponente = (jugador + 1) % 2;

    // Si hay un ganador, devuelvo más/menos infinito, según si he ganado yo o el oponente.
    if (ganador == jugador)
    {
        return gana;
    }
    else if (ganador == oponente)
    {
        return pierde;
    }
    else
    {
        // Colores que juega mi jugador y colores del oponente
        vector<color> my_colors = estado.getPlayerColors(jugador);
        vector<color> op_colors = estado.getPlayerColors(oponente);

        // Recorro todas las fichas de mi jugador
        int puntuacion_jugador = 0;
        // Recorro colores de mi jugador.
        for (int i = 0; i < my_colors.size(); i++)
        {
            color c = my_colors[i];
            // Recorro las fichas de ese color.
            for (int j = 0; j < num_pieces; j++)
            {
                // Valoro positivamente que la ficha esté en casilla segura o meta.
                if (estado.isSafePiece(c, j))
                {
                    puntuacion_jugador++;
                }
                else if (estado.getBoard().getPiece(c, j).type == goal)
                {
                    puntuacion_jugador += 5;
                }
            }
        }

        // Recorro todas las fichas del oponente
        int puntuacion_oponente = 0;
        // Recorro colores del oponente.
        for (int i = 0; i < op_colors.size(); i++)
        {
            color c = op_colors[i];
            // Recorro las fichas de ese color.
            for (int j = 0; j < num_pieces; j++)
            {
                if (estado.isSafePiece(c, j))
                {
                    // Valoro negativamente que la ficha esté en casilla segura o meta.
                    puntuacion_oponente++;
                }
                else if (estado.getBoard().getPiece(c, j).type == goal)
                {
                    puntuacion_oponente += 5;
                }
            }
        }

        // Devuelvo la puntuación de mi jugador menos la puntuación del oponente.
        return puntuacion_jugador - puntuacion_oponente;
    }
}


double AIPlayer::ValoracionMATANINJAS(const Parchis &estado, int jugador)
{
    int ganador = estado.getWinner();
    int oponente = (jugador + 1) % 2;

    // Si hay un ganador, devuelvo más/menos infinito, según si he ganado yo o el oponente.
    if (ganador == jugador)
    {
        return gana;
    }
    else if (ganador == oponente)
    {
        return pierde;
    }
    else
    {
        // Colores que juega mi jugador y colores del oponente
        vector<color> my_colors = estado.getPlayerColors(jugador);
        vector<color> op_colors = estado.getPlayerColors(oponente);

        // Recorro todas las fichas de mi jugador
        int puntuacion_jugador = 0;
        // Recorro colores de mi jugador.
        for (int i = 0; i < my_colors.size(); i++)
        {
            color c = my_colors[i];
            // Recorro las fichas de ese color.
            for (int j = 0; j < num_pieces; j++)
            {

                //Valoro positivamente que la pieza esté en el pasillo final

                if (estado.getBoard().getPiece(c,j).type == final_queue){
                    puntuacion_jugador += 900;
                }

                //Valoro positivamente que la pieza esté fuera de peligro
                
                if (estado.isSafePiece(c, j))
                {
                    puntuacion_jugador += 150;
                }

                //Valoro positivamente que la pieza forme parte de una barrera

                if (estado.isWall(estado.getBoard().getPiece(c,j)) == c ){
                    puntuacion_jugador += 400;
                }

                //Calculo la distancia a la meta y añado puntuación en función de la cercanía de la pieza

                int distancia_meta = estado.distanceToGoal(c, j);

                puntuacion_jugador += (80 - distancia_meta);

                //Si una pieza del oponente está en casa (es decir, una vez te la comes), se valora muy positivamente

                if (estado.getBoard().getPiece(op_colors[i],j).type == home){
                    puntuacion_jugador += 10000;
                }            
            }

            //Esta parte tiene en cuenta que es más valiosa una ficha en la meta cuantas más haya.

            if (estado.piecesAtGoal(my_colors[i]) == 1){
                puntuacion_jugador += 1000;
            }else if (estado.piecesAtGoal(my_colors[i]) == 2){
                puntuacion_jugador += 3000;
            }else if (estado.piecesAtGoal(my_colors[i]) == 3){
                puntuacion_jugador += 9000;
            }

        }

        // Recorro todas las fichas del oponente
        int puntuacion_oponente = 0;
        // Recorro colores del oponente.
        for (int i = 0; i < op_colors.size(); i++)
        {
            color c = op_colors[i];
            // Recorro las fichas de ese color.
            for (int j = 0; j < num_pieces; j++)
            {
                if (estado.getBoard().getPiece(c,j).type == final_queue){
                    puntuacion_oponente += 900;
                }

                if (estado.isSafePiece(c, j))
                {
                    puntuacion_oponente += 150;
                }

                if (estado.isWall(estado.getBoard().getPiece(c,j)) == c ){
                    puntuacion_oponente += 400;
                }

                int distancia_meta = estado.distanceToGoal(c, j);

                puntuacion_oponente += (80 - distancia_meta);

                if (estado.getBoard().getPiece(my_colors[i],j).type == home){
                    puntuacion_oponente += 10000;
                }
                
            }

        if (estado.piecesAtGoal(op_colors[i]) == 1){
            puntuacion_oponente += 1000;
        }else if (estado.piecesAtGoal(op_colors[i]) == 2){
            puntuacion_oponente += 3000;
        }else if (estado.piecesAtGoal(op_colors[i]) == 3){
            puntuacion_oponente += 9000;
        }


        }

        // Devuelvo la puntuación de mi jugador menos la puntuación del oponente.
        return puntuacion_jugador - puntuacion_oponente;
    }
}

