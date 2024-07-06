#include "interface.h"



Interface::Interface(Sample *sample, QWidget *parent) : QWidget(parent) {
    setWindowTitle("Работа №7");
    setFixedSize(400, 440);

    this->sample = sample;

    ChangeBtnFile = new QPushButton("Выберите файл", this);
    ChangeBtnFile->setGeometry(280, 405, 120, 30);
    connect(ChangeBtnFile, SIGNAL(pressed()), this, SLOT(changeFile()));
}


Interface::~Interface() {
    delete ChangeBtnFile;
    delete sample;
}


void Interface::paintEvent(QPaintEvent*) {
    QPainter painter;
    painter.begin(this);
    QRect rect(0, 0, 400, 400);
    sample->draw(&painter, rect);
    painter.end();
}

void Interface::changeFile(){
    short check = 0;
    Graph* graph;
    graph = new Graph();
    string NameFile = graph->selectFile();
    check = graph->InputFileValues(NameFile);
    if(check != 1){
        if (check == -1)      QMessageBox::information(nullptr, "Ошибка", "Файл не выбран\nНажмите ОК, чтобы выйти");
        else if (check == -2) QMessageBox::critical(nullptr, "Ошибка", "Неправильный ввод элементов");
        else if (check == -3) QMessageBox::critical(nullptr, "Ошибка", "Ненулевые значения диагонали матрицы");
    }
    sample->getGraph(graph);
    if (sample->empty()) close();
}

