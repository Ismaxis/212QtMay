#include "storage.h"

Storage::Storage()
{
    a = -1.0f;
    L0 = -1.0f;
    Q.QnpV = -1.0f;
    Q.Qnpm = -1.0f;
}

void Storage::set_a(float value)
{
    a = value;
}
void Storage::set_L0(float value)
{
    L0 = value;
}
void Storage::set_QnpV(float value){
    Q.QnpV = value;
}
void Storage::set_Qnpm(float value){
    Q.Qnpm = value;
}

float Storage::get_a()
{
    return a;
}
float Storage::get_L0()
{
    return L0;
}
QStruct Storage::get_Q()
{
    return Q;
}

bool Storage::isEmpty_a()
{
    return a == -1.0f;
}
bool Storage::isEmpty_L0()
{
    return L0 == -1.0f;
}
bool Storage::isEmpty_QnpV()
{
    return Q.QnpV == -1.0f;
}
bool Storage::isEmpty_Qnpm()
{
    return Q.Qnpm == -1.0f;
}


