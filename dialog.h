#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QString>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

protected slots:
    void make_crc16();

    void on_data_in_textChanged();
    void on_endian_clicked(bool isBigEndian);

private:
    Ui::Dialog *ui;
    bool m_isLittleEndian;
};

#endif // DIALOG_H
