#include <iostream>
#include <list>
#include <algorithm>
#include <utility>
#include <set>
using namespace std;

struct vertice{
    string name;
    int id;
};

struct edge{
    vertice v;
    int weight;
};

struct neighbours{
    vertice v;
    list <edge> l_of_nei;
};

list <neighbours> graph_data;

static int current_id = 0;
void add_verticle(string name){
    vertice temp_v;
    neighbours temp_n;
    temp_v.name = std::move(name);
    temp_v.id = current_id;
    current_id++;
    temp_n.v=temp_v;
    graph_data.push_back(temp_n);
}
void remove_verticle(vertice v){
    graph_data.erase(remove_if(graph_data.begin(),graph_data.end(),[=] (neighbours n){
        return (n.v.id == v.id)||(n.v.name == v.name); }));
    //list<neighbours>::iterator it;
    for (neighbours i :graph_data){
        i.l_of_nei.remove_if([=](edge e){return (e.v.id == v.id)||(e.v.name == v.name); });
    }
}
void add_edge(vertice v1, vertice v2, int weight){
    edge temp_e;
    for (neighbours i :graph_data){
        if (i.v.name == v1.name || i.v.id==v1.id){
            temp_e.v.id = v2.id;
            temp_e.v.name = v2.name;
            temp_e.weight = weight;
            i.l_of_nei.push_back(temp_e);
        }
        else if (i.v.name == v2.name || i.v.id==v2.id){
            temp_e.v.id = v1.id;
            temp_e.v.name = v1.name;
            temp_e.weight = weight;
            i.l_of_nei.push_back(temp_e);
        }

}
}
void remove_edge(vertice v1, vertice v2){
    for (neighbours i :graph_data) {
        if (i.v.name == v1.name || i.v.id==v1.id){
            i.l_of_nei.remove_if([=](edge e){return (e.v.id == v2.id)||(e.v.name == v2.name); });
        }
        else if (i.v.name == v2.name || i.v.id==v2.id){
            //i.l_of_nei.remove_if([=](edge e){return (e.v.id == v1.id)||(e.v.name == v1.name); });
            i.l_of_nei.erase(remove_if(i.l_of_nei.begin(),i.l_of_nei.end(),[=](edge e){
                return (e.v.id == v1.id)||(e.v.name == v1.name); }));
        }
    }
}


void change_egde_weight(vertice v1, vertice v2, int new_weigth){
    for (neighbours i :graph_data) {
        for (neighbours i :graph_data) {
            if (i.v.name == v1.name || i.v.id == v1.id) {
                for (edge j :i.l_of_nei){
                    if (j.v.name==v2.name || j.v.id==v2.id){
                        j.weight = new_weigth;
                    }
                }
            } else if (i.v.name == v2.name || i.v.id == v2.id) {
                for (edge j :i.l_of_nei){
                    if (j.v.name==v1.name || j.v.id==v1.id){
                        j.weight = new_weigth;
                    }
                }            }
        }
    }
}


set<vertice> already_used;//dodać funkcję która resetuje
bool is_there_path(vertice v1, vertice v2) {
    bool path = false;
    for (neighbours n :graph_data) {
        auto a = find_if(already_used.begin(), already_used.end(), [=](vertice v){ return n.v.name==v.name||n.v.id==v.id;});
        if (already_used.end()==a) {
            return false;
        }
        if (n.v.id == v1.id || n.v.name == v1.name) {
            for (edge e: n.l_of_nei) {
                already_used.insert(e.v);
                if (e.v.id == v2.id || e.v.name == v2.name) {
                    return true;
                } else {
                    path = path || is_there_path(e.v, v2);
                }

            }
        }
    }
}


int main() {
    std::list <int> l = {0,1,2,3,4,5,6,7,8,9};
    for (auto const& i : l) {
        std::cout << i << endl;
    }
    return 0;
}