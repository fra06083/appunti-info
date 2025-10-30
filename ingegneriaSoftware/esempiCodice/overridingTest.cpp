#include <iostream>

using namespace std;

class Graph {
public:
    virtual void draw() {
        cout << "in base\n";
    }
};

class LineGraph : public Graph {
public:
    virtual void draw() {
        cout << "in LineGraph\n";
    }
};

class PieChart : public Graph {
public:
    virtual void draw() {
        cout << "in piechart\n";
    }
};


int main() { 
    LineGraph lg;
    PieChart pc;
    lg.draw();

    Graph *p = &lg;
    p->draw();
    // rimuovi virtual da draw di graph e vedi che 
    // l'Overriding non funziona più
}


