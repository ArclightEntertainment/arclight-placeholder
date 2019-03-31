#ifndef CLIENTQUIZDIALOG_H
#define CLIENTQUIZDIALOG_H

#include <QObject>
#include "interface/Entity.h"

class ClientQuizDialog : public QDialog
{
    Q_OBJECT
public:
    explicit ClientQuizDialog(QWidget *parent = 0);
    virtual ~ClientQuizDialog();
signals:

public slots:
};

#endif // CLIENTQUIZDIALOG_H
