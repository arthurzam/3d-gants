#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->horizontalSlider->setSpan(5, 10);
    ui->horizontalSlider->setHandleMovementMode(QxtSpanSlider::NoOverlapping);

//    QxtSpanSlider* slider = new QxtSpanSlider();
//    ui->panel_timeline->addWidget(slider);
}

MainWindow::~MainWindow()
{
    delete ui;
}
