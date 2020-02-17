#include <iostream>
#include <queue>
#include <stack>
#include <cstring>
using namespace std;

int main() {
    string wyr = "1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+";
    queue <string> kolejka;
    string help;
    string siz;

    for (int i=0;i<size(wyr);i++){
        help = wyr[i];
        kolejka.push(help);
    }

    string current_part;
    stack <string> out_stack;
    queue <string> out_queue;
    string znaki = "()+-/*^ " ;
    bool dalej;
    for (int i=0;kolejka.size();i++){
        current_part = kolejka.front();
        kolejka.pop();
        if (isdigit(current_part[0])){ // są równe
            out_queue.push(current_part);
            //std::cout << current_part << "dodano" << std::endl;
        }
        else if (current_part[0] == znaki[0] ){
            out_stack.push(current_part);
            //std::cout << current_part << "dodano" << std::endl;
        }
        else if (current_part[0] == znaki[1]){
            dalej = true;
            string help4;
            while (dalej == true){
                //std::cout << out_stack.top() << "tutaj5" << std::endl;
                if (out_stack.top()[0] == znaki[0]) {
                    //std::cout << "tutaj1" << std::endl;
                    dalej = false;
                    //std::cout << out_stack.top() << "usunieto" << std::endl;
                    out_stack.pop();
                }
                else{
                    //std::cout << "tutaj2" << std::endl;
                    out_queue.push(out_stack.top());
                    //std::cout << out_stack.top() << "usunieto" << std::endl;
                    out_stack.pop();

                    //std::cout << "tutaj3" << std::endl;
                }
            }
        }
        else if (current_part[0] == znaki[2] || current_part[0] == znaki[3] ){

            while (size(out_stack)>0 && out_stack.top()[0]!=znaki[0]){
                    out_queue.push(out_stack.top());
                    //std::cout << out_stack.top() << "usunieto" << std::endl;
                    out_stack.pop();
                }
            out_stack.push(current_part);
            //std::cout << current_part << "dodano" << std::endl;
            }
        else if (current_part[0] == znaki[4] || current_part[0] == znaki[5]){
            dalej = true;
            while (dalej){
                if (out_stack.top()[0] == znaki[4] || out_stack.top()[0] == znaki[5] || current_part[0] == znaki[6]){
                    out_queue.push(out_stack.top());
                    //std::cout << out_stack.top() << "usunieto" << std::endl;
                    out_stack.pop();
                }
                else{
                    dalej = false;
                    out_stack.push(current_part);
                    //std::cout << current_part << "dodano" << std::endl;
                }
            }
        }
        else if(current_part[0] == znaki[6]){
            dalej = true;
            while (dalej){
                if (out_stack.top()[0] == znaki[6]){
                    out_queue.push(out_stack.top());
                    //std::cout << out_stack.top() << "usunieto" << std::endl;
                    out_stack.pop();
                }
                else{
                    dalej = false;
                    out_stack.push(current_part);
                    //std::cout << current_part << "dodano" << std::endl;
                }
            }
        }
    }
    while  (size(out_stack)>0){
        out_queue.push(out_stack.top());
        //std::cout << out_stack.top() << "usunieto" << std::endl;
        out_stack.pop();
    }

    string help3;
    for (int i=0;out_queue.size();i++){
        help3 = out_queue.front();
        out_queue.pop();
        std::cout << help3 << std::endl;
    }

    return 0;
}