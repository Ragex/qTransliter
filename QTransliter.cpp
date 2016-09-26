#include "QTransliter.h"
#include <QDebug>

// DLL version 0.9
// [+] Base functionality
// [+] add GOST 7.79-2000 format
//   [+] full support GOST 7.79-2000 format
// [~] add MVD RF format, but did't complete yet


QTransliter::QTransliter(QObject *p):QObject(p)
{
    massRusEngCapital.insert('À',"A");
    massRusEngCapital.insert('Á',"B");
    massRusEngCapital.insert('Â',"V");
    massRusEngCapital.insert('Ã',"G");
    massRusEngCapital.insert('Ä',"D");
    massRusEngCapital.insert('Å',"E");
    massRusEngCapital.insert('¨',"YO");
    massRusEngCapital.insert('Æ',"ZH");
    massRusEngCapital.insert('Ç',"Z");
    massRusEngCapital.insert('È',"I");
    massRusEngCapital.insert('É',"IY");
    massRusEngCapital.insert('Ê',"K");
    massRusEngCapital.insert('Ë',"L");
    massRusEngCapital.insert('Ì',"M");
    massRusEngCapital.insert('Í',"N");
    massRusEngCapital.insert('Î',"O");
    massRusEngCapital.insert('Ï',"P");
    massRusEngCapital.insert('Ð',"R");
    massRusEngCapital.insert('Ñ',"S");
    massRusEngCapital.insert('Ò',"T");
    massRusEngCapital.insert('Ó',"U");
    massRusEngCapital.insert('Ô',"F");
    massRusEngCapital.insert('Õ',"H");
    massRusEngCapital.insert('Ö',"TS");
    massRusEngCapital.insert('×',"CH");
    massRusEngCapital.insert('Ø',"SH");
    massRusEngCapital.insert('Ù',"SH'");
    massRusEngCapital.insert('Ú',"");
    massRusEngCapital.insert('Û',"Y");
    massRusEngCapital.insert('Ü',"'");
    massRusEngCapital.insert('Ý',"E'");
    massRusEngCapital.insert('Þ',"YU");
    massRusEngCapital.insert('ß',"YA");

    massRusEngSmall.insert('à',"a");
    massRusEngSmall.insert('á',"b");
    massRusEngSmall.insert('â',"v");
    massRusEngSmall.insert('ã',"g");
    massRusEngSmall.insert('ä',"d");
    massRusEngSmall.insert('å',"e");
    massRusEngSmall.insert('¸',"yo");
    massRusEngSmall.insert('æ',"zh");
    massRusEngSmall.insert('ç',"z");
    massRusEngSmall.insert('è',"i");
    massRusEngSmall.insert('é',"iy");
    massRusEngSmall.insert('ê',"k");
    massRusEngSmall.insert('ë',"l");
    massRusEngSmall.insert('ì',"m");
    massRusEngSmall.insert('í',"n");
    massRusEngSmall.insert('î',"o");
    massRusEngSmall.insert('ï',"p");
    massRusEngSmall.insert('ð',"r");
    massRusEngSmall.insert('ñ',"s");
    massRusEngSmall.insert('ò',"t");
    massRusEngSmall.insert('ó',"u");
    massRusEngSmall.insert('ô',"f");
    massRusEngSmall.insert('õ',"h");
    massRusEngSmall.insert('ö',"ts");
    massRusEngSmall.insert('÷',"ch");
    massRusEngSmall.insert('ø',"sh");
    massRusEngSmall.insert('ù',"sh'");
    massRusEngSmall.insert('ú',"");
    massRusEngSmall.insert('û',"y");
    massRusEngSmall.insert('ü',"'");
    massRusEngSmall.insert('ý',"e'");
    massRusEngSmall.insert('þ',"yu");
    massRusEngSmall.insert('ÿ',"ya");
}

QString QTransliter::translate(QString text, int dictionary, int standart)
{
    QString tmpBuff;

    tmpBuff.clear();

    massRusEngCapital.insert('É',"IY");
    massRusEngCapital.insert('Ö',"TS");
    massRusEngCapital.insert('Õ',"H");
    massRusEngCapital.insert('Ù',"SH'");
    massRusEngCapital.insert('Ú',"");
    massRusEngCapital.insert('Ý',"E'");

    massRusEngSmall.insert('é',"iy");
    massRusEngSmall.insert('ö',"ts");
    massRusEngSmall.insert('õ',"h");
    massRusEngSmall.insert('ù',"sh'");
    massRusEngSmall.insert('ú',"");
    massRusEngSmall.insert('ý',"e'");

    switch(standart){

           default:
           case Default: break;

           case GOST_7_79_2000: massRusEngCapital.insert('É',"J");
                                massRusEngCapital.insert('Ö',"C");
                                massRusEngCapital.insert('Ù',"SHH");
                                massRusEngCapital.insert('Ú',"\"");

                                massRusEngSmall.insert('é',"j");
                                massRusEngSmall.insert('ö',"c");
                                massRusEngSmall.insert('ù',"shh");
                                massRusEngSmall.insert('ú',"\"");
                                break;

           case MVD_RF: massRusEngCapital.insert('É',"Y");
                        massRusEngCapital.insert('Õ',"KH");
                        massRusEngCapital.insert('Ù',"SHCH");
                        massRusEngCapital.insert('Ú',"'");
                        massRusEngCapital.insert('Ý',"E");

                        massRusEngSmall.insert('é',"y");
                        massRusEngSmall.insert('õ',"kh");
                        massRusEngSmall.insert('ù',"shch");
                        massRusEngSmall.insert('ú',"'");
                        massRusEngSmall.insert('ý',"e");

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

                tmpBuff.replace("ûû","ûé",Qt::CaseInsensitive);
                tmpBuff.replace("éé","ûé",Qt::CaseInsensitive);


                for(int charPos=1;charPos<tmpBuff.size();charPos++){
                    if(tmpBuff.data()[charPos] == 'Ü' && massRusEngSmall.contains(tmpBuff.data()[charPos-1]))
                       tmpBuff.data()[charPos] = 'ü';

                    if(tmpBuff.data()[charPos] == 'Ú' && massRusEngSmall.contains(tmpBuff.data()[charPos-1]))
                       tmpBuff.data()[charPos] = 'ú';
                }

                break;
    }

    return tmpBuff;
}


void QTransliter::sltTranslate(QString str, int direction, int standart)
{
    emit translitReady(this->translate(str,direction,standart));
}
