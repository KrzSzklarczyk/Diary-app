#include "text_holder.h"

Text_Holder::Text_Holder(QString data, QString napis)
{
    m_napis = napis;
    m_data = data;
}

Text_Holder::~Text_Holder()
{

}

void Text_Holder::SetNapis(QString napis)
{
    m_napis = napis;
}

void Text_Holder::SetData(QString data)
{
    m_data = data;
}

QString Text_Holder::GetData()
{
    return m_data;
}

QString Text_Holder::GetNapis()
{
    return m_napis;
}

QString Text_Holder::GetIndex()
{
    return m_data + " " + m_napis;
}

void Text_Holder::SetTyp(Typ t)
{
    m_typ = t;
}

Typ Text_Holder::GetTyp()
{
    return m_typ;
}

bool Text_Holder::operator==(const Text_Holder &t)
{
    if(this!=&t)
        return (this->m_data == t.m_data);
    return true;
}

bool Text_Holder::operator!=(const Text_Holder &t)
{
    return !(*this == t);
}

bool Text_Holder::operator<(const Text_Holder &t)
{
    if(this!=&t)
        return (this->m_data<t.m_data);
    return true;
}







