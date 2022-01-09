#ifndef VUIPUSHBUTTON_H
#define VUIPUSHBUTTON_H
#include <QPushButton>
#include <QStyleOptionButton>
#include <QIcon>

class VuiCashPushButton : public QPushButton
{
public:
    explicit VuiCashPushButton(QWidget * parent = Q_NULLPTR);
    explicit VuiCashPushButton(const QString &text, QWidget *parent = Q_NULLPTR);

protected:
    void paintEvent(QPaintEvent *) Q_DECL_OVERRIDE;

private:
    void updateIcon(QStyleOptionButton &pushbutton);

private:
    bool m_iconCached;
    QIcon m_downIcon;
};

#endif // VUIPUSHBUTTON_H
