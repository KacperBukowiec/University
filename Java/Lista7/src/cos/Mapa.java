package cos;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class Mapa {
     public Komnata[][] map;
     public int n;
    Mapa(int x){
        n=x;

        map = new Komnata[n][n];
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                map[i][j] = new Komnata(false,false,false,false);

            }
        }
    generate();
    }
    public static int rand03(){
        Random r = new Random();
        return r.ints(0, (3 + 1)).findFirst().getAsInt();
    }

    boolean posAvaible(int x,int y,int direction){
        if (x==0 && direction==0) return false;
        if (x==n-1 && direction==2) return false;
        if (y==0 && direction==1) return false;
        if (y==n-1 && direction==3) return false;
        if (!(x==0) && map[x - 1][y].usedInGeneration == false && direction == 0) return true;
        if (!(y==n-1) && map[x][y+1].usedInGeneration ==false && direction==3) return true;
        if (!(x==n-1) &&map[x+1][y].usedInGeneration ==false && direction==2) return true;
        if (!(y==0) && map[x][y-1].usedInGeneration ==false && direction==1) return true;
        return false;

    }
    int anyPosAvaible(int x,int y){
        if (posAvaible(x,y,0)) return 0;
        if (posAvaible(x,y,1)) return 1;
        if (posAvaible(x,y,2)) return 2;
        if (posAvaible(x,y,3)) return 3;
        // 4 jeśli żadna nie jest dobra
        return 4;
    }

    int nextMoveDirection(int x,int y){
        int dir = rand03();
        if ((posAvaible(x,y,dir))) return dir;
        //sprawdzxić cz nie zraca 4
        return anyPosAvaible(x,y);

    }
    void generate(){
        List stack = new ArrayList();
        //domyślny początek
        int posX=1;
        int posY=0;
        map[posX][posY].usedInGeneration=true;
        map[0][0].usedInGeneration=true;
        map[0][0].w2=true;
        map[1][0].w0=true;
        stack.add(0);
        while (!(stack.size()==0)) {
        int nex=nextMoveDirection(posX,posY);
            if (nex==0){
                map[posX][posY].w0=true;
                posX -=1;
                map[posX][posY].w2=true;
                stack.add(2);
            }
            if (nex==2){
                map[posX][posY].w2=true;
                posX +=1;
                map[posX][posY].w0=true;
                stack.add(0);
            }
            if (nex==1){
                map[posX][posY].w1=true;
                posY -=1;
                map[posX][posY].w3=true;
                stack.add(3);
            }
            if (nex==3){
                map[posX][posY].w3=true;
                posY +=1;
                map[posX][posY].w1=true;
                stack.add(1);
            }
            if (nex==4) {
                //System.out.println("wuwwwwwwwwww");
                int last = (int) stack.get(stack.size() - 1);
                stack.remove(stack.size()-1);
                if (last == 0) {
                    posX -= 1;
                }
                if (last == 2) {
                    posX += 1;
                }
                if (last == 1) {
                    posY -= 1;
                }
                if (last == 3) {
                    posY += 1;
                }
            }
            map[posX][posY].usedInGeneration=true;
            //System.out.println(posX);
            //System.out.println(posY);
            //System.out.println("---------------------------");
            }


        }


    }

