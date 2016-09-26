#include "QTransliter.h"
#include <QDebug>

// DLL version 0.9
// [+] Base functionality
// [+] add GOST 7.79-2000 format
//   [+] full support GOST 7.79-2000 format
// [~] add MVD RF format, but did't complete yet


QTransliter::QTransliter(QObject *p):QObject(p)
{
    massRusEngCapital.insert('�',"A");
    massRusEngCapital.insert('�',"B");
    massRusEngCapital.insert('�',"V");
    massRusEngCapital.insert('�',"G");
    massRusEngCapital.insert('�',"D");
    massRusEngCapital.insert('�',"E");
    massRusEngCapital.insert('�',"YO");
    massRusEngCapital.insert('�',"ZH");
    massRusEngCapital.insert('�',"Z");
    massRusEngCapital.insert('�',"I");
    massRusEngCapital.insert('�',"IY");
    massRusEngCapital.insert('�',"K");
    massRusEngCapital.insert('�',"L");
    massRusEngCapital.insert('�',"M");
    massRusEngCapital.insert('�',"N");
    massRusEngCapital.insert('�',"O");
    massRusEngCapital.insert('�',"P");
    massRusEngCapital.insert('�',"R");
    massRusEngCapital.insert('�',"S");
    massRusEngCapital.insert('�',"T");
    massRusEngCapital.insert('�',"U");
    massRusEngCapital.insert('�',"F");
    massRusEngCapital.insert('�',"H");
    massRusEngCapital.insert('�',"TS");
    massRusEngCapital.insert('�',"CH");
    massRusEngCapital.insert('�',"SH");
    massRusEngCapital.insert('�',"SH'");
    massRusEngCapital.insert('�',"");
    massRusEngCapital.insert('�',"Y");
    massRusEngCapital.insert('�',"'");
    massRusEngCapital.insert('�',"E'");
    massRusEngCapital.insert('�',"YU");
    massRusEngCapital.insert('�',"YA");

    massRusEngSmall.insert('�',"a");
    massRusEngSmall.insert('�',"b");
    massRusEngSmall.insert('�',"v");
    massRusEngSmall.insert('�',"g");
    massRusEngSmall.insert('�',"d");
    massRusEngSmall.insert('�',"e");
    massRusEngSmall.insert('�',"yo");
    massRusEngSmall.insert('�',"zh");
    massRusEngSmall.insert('�',"z");
    massRusEngSmall.insert('�',"i");
    massRusEngSmall.insert('�',"iy");
    massRusEngSmall.insert('�',"k");
    massRusEngSmall.insert('�',"l");
    massRusEngSmall.insert('�',"m");
    massRusEngSmall.insert('�',"n");
    massRusEngSmall.insert('�',"o");
    massRusEngSmall.insert('�',"p");
    massRusEngSmall.insert('�',"r");
    massRusEngSmall.insert('�',"s");
    massRusEngSmall.insert('�',"t");
    massRusEngSmall.insert('�',"u");
    massRusEngSmall.insert('�',"f");
    massRusEngSmall.insert('�',"h");
    massRusEngSmall.insert('�',"ts");
    massRusEngSmall.insert('�',"ch");
    massRusEngSmall.insert('�',"sh");
    massRusEngSmall.insert('�',"sh'");
    massRusEngSmall.insert('�',"");
    massRusEngSmall.insert('�',"y");
    massRusEngSmall.insert('�',"'");
    massRusEngSmall.insert('�',"e'");
    massRusEngSmall.insert('�',"yu");
    massRusEngSmall.insert('�',"ya");
}

QString QTransliter::translate(QString text, int dictionary, int standart)
{
    QString tmpBuff;

    tmpBuff.clear();

    massRusEngCapital.insert('�',"IY");
    massRusEngCapital.insert('�',"TS");
    massRusEngCapital.insert('�',"H");
    massRusEngCapital.insert('�',"SH'");
    massRusEngCapital.insert('�',"");
    massRusEngCapital.insert('�',"E'");

    massRusEngSmall.insert('�',"iy");
    massRusEngSmall.insert('�',"ts");
    massRusEngSmall.insert('�',"h");
    massRusEngSmall.insert('�',"sh'");
    massRusEngSmall.insert('�',"");
    massRusEngSmall.insert('�',"e'");

    switch(standart){

           default:
           case Default: break;

           case GOST_7_79_2000: massRusEngCapital.insert('�',"J");
                                massRusEngCapital.insert('�',"C");
                                massRusEngCapital.insert('�',"SHH");
                                massRusEngCapital.insert('�',"\"");

                                massRusEngSmall.insert('�',"j");
                                massRusEngSmall.insert('�',"c");
                                massRusEngSmall.insert('�',"shh");
                                massRusEngSmall.insert('�',"\"");
                                break;

           case MVD_RF: massRusEngCapital.insert('�',"Y");
                        massRusEngCapital.insert('�',"KH");
                        massRusEngCapital.insert('�',"SHCH");
                        massRusEngCapital.insert('�',"'");
                        massRusEngCapital.insert('�',"E");

                        massRusEngSmall.insert('�',"y");
                        massRusEngSmall.insert('�',"kh");
                        massRusEngSmall.insert('�',"shch");
                        massRusEngSmall.insert('�',"'");
                        massRusEngSmall.insert('�',"e");

                        break;
    }


    QMap<QChar,QString>::const_iterator iBigChar = massRusEngCapital.constBegin();

    charMaxLength = iBigChar.value().size();

    while(iBigChar != massRusEngCapital.constEnd())
    {
        if(charMaxLength < iBigChar.value().size()) charMaxLength = iBigChar.value().size();
        iBigChar++;
    }


    switch(dictionary){
           case RU_ENG:
                for(int cnt=0;cnt<text.size();cnt++){
                    if(massRusEngSmall.contains(text.data()[cnt]))
                       tmpBuff.append(massRusEngSmall.value(text.data()[cnt]));
                    else
                        tmpBuff.append(massRusEngCapital.value(text.data()[cnt],text.data()[cnt]));
                }
                break;

           case ENG_RU:
                QMap<QChar,QString>::const_iterator iCharStore = massRusEngCapital.constBegin();

                tmpBuff = text;

                for(int i=charMaxLength;i>=1;i--){
                    while(iCharStore != massRusEngCapital.constEnd())
                    {
                     if(iCharStore.value().size() == i && iCharStore.value() != "")
                        tmpBuff.replace(iCharStore.value(),iCharStore.key());

                     iCharStore++;
                    }
                    iCharStore = massRusEngCapital.constBegin();
                }


                iCharStore = massRusEngSmall.constBegin();
                for(int i=charMaxLength;i>=1;i--){
                    while(iCharStore != massRusEngSmall.constEnd())
                    {
                     if(iCharStore.value().size() == i && iCharStore.value() != "")
                        tmpBuff.replace(iCharStore.value(),iCharStore.key());

                     iCharStore++;
                    }
                    iCharStore = massRusEngSmall.constBegin();
                }

                tmpBuff.replace("��","��",Qt::CaseInsensitive);
                tmpBuff.replace("��","��",Qt::CaseInsensitive);


                for(int charPos=1;charPos<tmpBuff.size();charPos++){
                    if(tmpBuff.data()[charPos] == '�' && massRusEngSmall.contains(tmpBuff.data()[charPos-1]))
                       tmpBuff.data()[charPos] = '�';

                    if(tmpBuff.data()[charPos] == '�' && massRusEngSmall.contains(tmpBuff.data()[charPos-1]))
                       tmpBuff.data()[charPos] = '�';
                }

                break;
    }

    return tmpBuff;
}


void QTransliter::sltTranslate(QString str, int direction, int standart)
{
    emit translitReady(this->translate(str,direction,standart));
}
