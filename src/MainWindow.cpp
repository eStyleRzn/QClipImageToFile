#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  connect(ui->lineEdit, SIGNAL(imagePasted(const QString&)), this, SLOT(onImagePasted(const QString&)));
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::onImagePasted(const QString& fileName)
{
  QPixmap img(fileName);
  ui->label->setPixmap(img);
  ui->lineInfo->setText(fileName);
}
