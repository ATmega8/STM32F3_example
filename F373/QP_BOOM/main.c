/*****************************************************************************
* Model: model.qm
* File:  Code/main.c
*
* This code has been generated by QM tool (see state-machine.com/qm).
* DO NOT EDIT THIS FILE MANUALLY. All your changes will be lost.
*
* This program is open source software: you can redistribute it and/or
* modify it under the terms of the GNU General Public License as published
* by the Free Software Foundation.
*
* This program is distributed in the hope that it will be useful, but
* WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
* or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
* for more details.
*****************************************************************************/
/*L. 2014*/
/* @(/2/0) .................................................................*/
#include "main.h"


/* @(/1/0) .................................................................*/
typedef struct MyAOTag {
/* protected: */
    QActive super;

/* private: */
    QTimeEvt TimeEvt;

/* public: */
    uint8_t timeout;

/* private: */
    uint8_t code;
    uint8_t defuse;
} MyAO;

/* protected: */
static QState MyAO_initial(MyAO * const me, QEvt const * const e);
static QState MyAO_SET(MyAO * const me, QEvt const * const e);
static QState MyAO_Timing(MyAO * const me, QEvt const * const e);

/* @(/1/0) .................................................................*/
/* @(/1/0/4) ...............................................................*/
/* @(/1/0/4/0) */
static QState MyAO_initial(MyAO * const me, QEvt const * const e) {
    me->timeout = INIT_TIMEOUT;
    me->defuse = INIT_DEFUSE;
    return Q_TRAN(&MyAO_SET);
}
/* @(/1/0/4/1) .............................................................*/
static QState MyAO_SET(MyAO * const me, QEvt const * const e) {
    QState status_;
    switch (e->sig) {
        /* @(/1/0/4/1/0) */
        case ARM_SIG: {
            me->code = 0;
            status_ = Q_TRAN(&MyAO_Timing);
            break;
        }
        /* @(/1/0/4/1/1) */
        case DOWN_SIG: {
            /* @(/1/0/4/1/1/0) */
            if (me->timeout > 1) {
                --me->timeout;
                BSP_display_timeout();
                status_ = Q_HANDLED();
            }
            else {
                status_ = Q_UNHANDLED();
            }
            break;
        }
        /* @(/1/0/4/1/2) */
        case UP_SIG: {
            /* @(/1/0/4/1/2/0) */
            if (me->timeout < 60) {
                ++me->timeout;
                BSP_display_timeout();
                status_ = Q_HANDLED();
            }
            else {
                status_ = Q_UNHANDLED();
            }
            break;
        }
        default: {
            status_ = Q_SUPER(&QHsm_top);
            break;
        }
    }
    return status_;
}
/* @(/1/0/4/2) .............................................................*/
static QState MyAO_Timing(MyAO * const me, QEvt const * const e) {
    QState status_;
    switch (e->sig) {
        /* @(/1/0/4/2/0) */
        case ARM_SIG: {
            /* @(/1/0/4/2/0/0) */
            if (me->code == me->defuse) {
                status_ = Q_TRAN(&MyAO_SET);
            }
            else {
                status_ = Q_UNHANDLED();
            }
            break;
        }
        /* @(/1/0/4/2/1) */
        case UP_SIG: {
            me->code <<= 1;
            me->code |= 1;
            status_ = Q_HANDLED();
            break;
        }
        /* @(/1/0/4/2/2) */
        case DOWN_SIG: {
            me->code <<= 1;
            status_ = Q_HANDLED();
            break;
        }
        /* @(/1/0/4/2/3) */
        case TIMEOUT_SIG: {
            --me->timeout;
            BSP_display_timeout();
            /* @(/1/0/4/2/3/0) */
            if (me->timeout == 0) {
                BSP_Boom();
                status_ = Q_HANDLED();
            }
            /* @(/1/0/4/2/3/1) */
            else {
                status_ = Q_TRAN(&MyAO_Timing);
            }
            break;
        }
        default: {
            status_ = Q_SUPER(&QHsm_top);
            break;
        }
    }
    return status_;
}

