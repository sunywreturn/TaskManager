#pragma once
#include <QPainter>
#include <QStyledItemDelegate>
#include <QDate>
#include <QMap>

class CalendarDelegate : public QStyledItemDelegate {
public:
    explicit CalendarDelegate(QMap<QDate, QStringList> tasks, QObject* parent = nullptr);

    void paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const override;

private:
    QMap<QDate, QStringList> m_tasks;
};