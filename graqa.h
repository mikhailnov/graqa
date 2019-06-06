#ifndef GRAQA_H
#define GRAQA_H

#include <QMainWindow>
#include <qcustomplot.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void makePlot();
private:
    Ui::MainWindow *ui;
};

#endif // GRAQA_H
