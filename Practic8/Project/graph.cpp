#include "graph.h"

Graph::Graph(){
    count = 0;
}

vector<Node*> Graph::getNodes() const {
    return nodes;
}

int Graph::size() const {
    return nodes.size();
}
bool Graph::empty() {
    return nodes.empty();
}

void Graph::addNode(char name_val) {
    Node* newNode = new Node();
    newNode->name = name_val;
    nodes.push_back(newNode);
}

void Graph::addEdge(Node* from, Node* to) {
    from->neighbors.push_back(to);
}

string Graph::selectFile(){
    QFile filename = QFileDialog::getOpenFileName(
    nullptr,
    "Выберите файл для открытия",
    "../../Practic8",
    "Text Files (*.txt)");

    return filename.fileName().toStdString();
}

short Graph::InputFileValues(string filename){
    string line = "";
    count = 0;
    ifstream InputFile(filename);
    if (!InputFile.is_open()) return -1;

    //считывание вершин с матрицы
    getline(InputFile, line);
    string name;
    vector<char> names;
    for (auto &c : line) {
        if (c == ' ') {
            if (!name.empty()) names.push_back(name[0]);
            name.clear();
            count++;
        } else {
            name += c;
            if (name.length() > 1) return -2;
        }
    }
    names.push_back(name[0]);
    for(int i = 0; i < count; i++){
        addNode(names[i]);
    }

    //считывание данных с файла
    vector<vector<int>> values;
    while (getline(InputFile, line)) {
        vector<int> row;
        for(int i = 0; i < line.length(); i++){
            if (line[i]!= ' '){
                if(line[i]== '0' || line[i]=='1') row.push_back(line[i] - '0');
                else return -2;
            }
        }
        values.push_back(row);
    }
    for (int i = 0; i < values.size(); ++i) if (values[i][i] != 0) return -3;


    //добавление связей вершин
    for(int i = 0; i < count; i++){
        for(int j = 0; j < count; j++){
            if(values[i][j] == 1){
                addEdge(nodes[j], nodes[i]);
            }
        }
        cout << endl;
    }

    InputFile.close();
    return 1;
}
