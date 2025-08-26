#ifndef URDUTEXTEDIT_H
#define URDUTEXTEDIT_H

#include <QTextEdit>
#include <QKeyEvent>

class UrduTextEdit : public QTextEdit
{
    Q_OBJECT

public:
    explicit UrduTextEdit(QWidget *parent = nullptr);

protected:
    void keyPressEvent(QKeyEvent *event) override;

private:
    void setupEditor();
};

#endif // URDUTEXTEDIT_H
