#include "dialog.h"
#include "ui_dialog.h"
#include "Util/crc16.h"
#include <QDebug>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_data_in_textChanged()
{
    make_crc16();
}

void Dialog::on_endian_clicked(bool isBigEndian)
{
    m_isLittleEndian = !isBigEndian;
    make_crc16();
}

void Dialog::make_crc16()
{
    QString text = ui->data_in->toPlainText();
    qDebug() << text;
    QStringList textArray = text.split(" ");

    int data_len = textArray.length();
    ui->len_out->setText(QString().sprintf("%d", data_len));
    if (data_len == 0)
        return;

    quint8 *data_buff = new quint8 [data_len];

    bool ok = false;
    for (int i = 0; i < data_len; ++i) {
        QString tmp = textArray[i];
        quint8 value = tmp.toInt(&ok, 16);
        if (!ok)
            break;
        data_buff[i] = value;
    }

    if (ok) {
        quint16 crc = GenerateCRC16(data_buff, data_len);
        quint8 tmp[2];

        if (m_isLittleEndian) {
            tmp[0] = crc & 0xff;
            tmp[1] = crc >> 8;
        } else {
            tmp[1] = crc & 0xff;
            tmp[0] = crc >> 8;
        }
        QString output = QString().sprintf("%02X %02X", tmp[0], tmp[1]);
        ui->crc16_out->setText(output);
    }

    delete [] data_buff;
}
