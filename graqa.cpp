#include "graqa.h"
#include "ui_graqa.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MainWindow::makePlot();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::makePlot()
{
    const int num=505; // кол-во точек для построения графика
    const float x_step=0.1;

    int k=1;
    QVector<double> x(num), y(num);
    x[0] = 0.0;
    double sum_k=0.0;
    for (int i=0; i<num; i++)
    {
        for (int i=0; i<k; i++)
        {
            sum_k += (qPow(-1, k+1))*qCos(k*x[i])/(qPow(2*k, 2)-1);
        }
        y[i] = (4/M_PI)*(0.5+sum_k);
        std::cout << "x[" << i << "] = " << x[i] << " :: "
                  << "y[" << i << "] = " << y[i] << " :: "
                  << "k = " << k << " :: "
                  << "sum_k = " << sum_k
                  << "\n";
        if ((i+1) < num) {
            x[i+1] = x[i]+x_step;
        }
        k++;
    }

    // create graph and assign data to it:
    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(x, y);
    // give the axes some labels:
    ui->customPlot->xAxis->setLabel("x");
    ui->customPlot->yAxis->setLabel("y");
    // set axes ranges, so we see all data:
    //ui->customPlot->xAxis->setRange(-1, 1);
    ui->customPlot->yAxis->setRange(0.89, 1.08);
    ui->customPlot->replot();
}
