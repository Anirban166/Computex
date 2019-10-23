#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "msp.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::plotGraph(std::string inputString, int times){
    msp myMsp(inputString);
    const int twoPi = 630; // one complete cycle
    int flag = 0;

    QVector<double> x1(twoPi*times), y1(twoPi*times); // initialize with entries 0..100
    QVector<double> x2(twoPi*times), y2(twoPi*times);

    for (int i = 0; i<inputString.length(); i++){
        std::string s = inputString;
        if ((s[i] == 'c' && s[i + 1] == 's' && s[i + 2] == 'c') || (s[i] == 'c' && s[i + 1] == 'o' && s[i + 2] == 't')){
            // generate some data
            x1.pop_back(); x2.pop_back();
            y1.pop_back(); y2.pop_back();
            for(double i=1; i<twoPi*times-1; ++i){
                // left graph
                x1[i] = -i/100.0;
                y1[i] = myMsp.returnYvalue(x1[i]);
                // right graph
                x2[i] = i/100.0;
                y2[i] = myMsp.returnYvalue(x2[i]);
            }
            flag = 1;
        }
    }

    if(flag == 0){
        // generate some data
        for(double i=0; i<twoPi*times; ++i){
            // left graph
            x1[i] = -i/100.0;
            y1[i] = myMsp.returnYvalue(x1[i]);
            // right graph
            x2[i] = i/100.0;
            y2[i] = myMsp.returnYvalue(x2[i]);
        }
    }


    // create graph and assign data to it
    ui->WidCustomPlot->addGraph();
    ui->WidCustomPlot->graph(0)->setData(x1,y1);
    ui->WidCustomPlot->addGraph();
    ui->WidCustomPlot->graph(1)->setData(x2,y2);
    // give the axes some labels
    ui->WidCustomPlot->xAxis->setLabel("X");
    ui->WidCustomPlot->yAxis->setLabel("Y");
    // set axes ranges, so we see all data
    ui->WidCustomPlot->xAxis->setRange(-5,5);
    ui->WidCustomPlot->yAxis->setRange(-5,5);
    //ui->WidCustomPlot->graph(0)->rescaleAxes(); // this will automatically resccale the view as the size of graph
    //ui->WidCustomPlot->graph(1)->rescaleAxes(true);
    ui->WidCustomPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    ui->WidCustomPlot->replot();
}

void MainWindow::clearAllGraph(){
    ui->WidCustomPlot->clearGraphs();
    ui->WidCustomPlot->replot();
}

void MainWindow::on_btnPlott_clicked()
{
    std::string input;
    QString inputString = ui->textEdit->toPlainText();
    input = inputString.toStdString();

    int times = 1;
    times = ui->spinBox->value();

    plotGraph(input, times);
}

void MainWindow::on_btnClear_clicked()
{
    clearAllGraph();
}

