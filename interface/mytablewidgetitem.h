#ifndef MYTABLEWIDGETITEM_H
#define MYTABLEWIDGETITEM_H
#include <QTableWidgetItem>

class MyTableWidgetItem : public QTableWidgetItem {
public:
    MyTableWidgetItem(QString data = "");
    bool operator <(const QTableWidgetItem &other) const;

    QVariant data(int role) const;

private:
        QString m_data;
};

#endif // MYTABLEWIDGETITEM_H
