#include <vector>
#include "Game_token.h" 
#include "Board_space.h"
#include "Board.h"


namespace Grid_game
{

    void Token::move(direction dir){  
        int xPrevious = x; 
        int yPrevious = y; 
 
        if(dir == 1){
            if( board.width()-1 == x )
                return;
            x++;
            
            if( board.retrieve_space(x,y).type() == 1 ){
                x = xPrevious;
                y = yPrevious;
            } 
            return;
        } 
        if(dir == 3){
            if( 0 == x ){
                return; 
            }
            --x;
            
            if( board.retrieve_space(x,y).type() == 1 ){
                x = xPrevious;
                y = yPrevious;
            } 
            return;
        }
        if(dir == 0){
            if( 0 == y )
                return;
            --y;
            if( board.retrieve_space(x,y).type() == 1 ){
                x = xPrevious;
                y = yPrevious;
            } 
            return;
        } 

        if(dir == 2){
            if( board.height() == y )
                return;
            y++;
            
            if( board.retrieve_space(x,y).type() == 1 ){
                x = xPrevious;
                y = yPrevious;
            } 
            return;
        }

    }
    
    void Token::move_special(vector<direction> vDir){}

    void Token::apply_terrain_effect(const Space::terrain_type terr){
        try{
            //empty space
           if(terr == 0) {
                return;
            } 
            //wall / barrier
            if(terr == 1) {
                return;
            }

            //water 
            if(terr == 2) {
                //reduce hp and pp
                hp = hp -1;
                pp = pp -1;
                return;
            }

            //lava
            if(terr == 3) 
            {
                hp = 0;
                pp = 0;
                return; 
            }
        }
        catch(const std::exception& e)
        {
        std::cerr << e.what() << '\n';
        }
        
    }
}
