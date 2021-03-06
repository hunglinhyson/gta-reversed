#pragma once
#include "CTaskSimple.h"
#include "CVector.h"

class CTaskSimpleGoTo : public CTaskSimple
{
    CTaskSimpleGoTo() = delete;
public:
    int     m_moveState;
    CVector m_targetPoint;
    float   m_fRadius;
    unsigned char flags;
    unsigned char field_1D[3];
    unsigned char field_20;
    unsigned char field_21[3];
};

VALIDATE_SIZE(CTaskSimpleGoTo, 0x24);