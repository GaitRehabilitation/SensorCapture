#include "ui_mainwindow.h"

#include "forms/deviceselectdialog.h"
#include "forms/mainwindow.h"

#include <QtDebug>
#include <QFileDialog>
#include "forms/sensorpanel.h"

MainWindow::MainWindow(QWidget *parent  )
    :QMainWindow(parent),
     ui(new Ui::MainWindow)//,
//     saveDialog(new QFileDialog(this))
{
    ui->setupUi(this);
    ui->save->setDisabled(true);

    connect(ui->actionAddDevice,SIGNAL(triggered()),this,SLOT(deviceAddWizard()));
}


void MainWindow::deviceAddWizard(){
  DeviceSelectDialog deviceSelectDialog(this);
  connect(&deviceSelectDialog,SIGNAL(onBluetoothDeviceAccepted(QBluetoothDeviceInfo)),this,SLOT(registerDevice(QBluetoothDeviceInfo)));
  deviceSelectDialog.exec();
}

void MainWindow::registerDevice(const QBluetoothDeviceInfo& info){
    //created a new list widget
    QListWidgetItem *listWidgetItem = new QListWidgetItem(ui->sensorList);

    ui->sensorList->addItem(listWidgetItem);

    SensorPanel* sensorPanel = new SensorPanel(this);
    sensorPanel->setDevice(info);

    //make the widget the same size as the panel
    listWidgetItem->setSizeHint(sensorPanel->sizeHint());

    ui->sensorList->setItemWidget(listWidgetItem,sensorPanel);
}

MainWindow::~MainWindow(){
    delete ui;
}

