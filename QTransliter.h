#ifndef QTRANSLITER_H
#define QTRANSLITER_H

#include <QObject>
#include <QMap>
#include <QString>
#include <QChar>

#include "qtransliter_global.h"


class QTRANSLITERSHARED_EXPORT QTransliter: public QObject
{
    Q_OBJECT

private:
    QMap<QChar,QString> massRusEngCapital,massRusEngSmall;
    int charMaxLength;

public:
    enum Dictionary
    {
        RU_ENG,
        ENG_RU
    };

    enum Standart
    {
        Default,
        GOST_7_79_2000,
        MVD_RF
    };

    explicit QTransliter(QObject *p=0);
    QString translate(QString text, int dictionary, int standart);

signals:
    void translitReady(QString text);

public slots:
    void sltTranslate(QString str, int direction, int standart);
};

#endif // QTRANSLITER_H
