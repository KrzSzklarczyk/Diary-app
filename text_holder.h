#ifndef TEXT_HOLDER_H
#define TEXT_HOLDER_H

#include <QString>

enum class Typ
{
    Smutne, Neutralne, Radosne
};

class Text_Holder
{
private:
    QString m_napis;
    QString m_data;
    Typ m_typ;
public:
    Text_Holder(QString data, QString napis);
    ~Text_Holder();
    void SetNapis(QString napis);
    void SetData(QString data);
    void SetTyp(Typ t);
    Typ GetTyp();
    QString GetNapis();
    QString GetData();
    QString GetIndex();
    bool operator==(const Text_Holder &t);
    bool operator!=(const Text_Holder &t);
    bool operator<(const Text_Holder &t);
};

#endif // TEXT_HOLDER_H
