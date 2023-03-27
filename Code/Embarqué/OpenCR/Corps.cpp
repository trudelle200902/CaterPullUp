/***
 * @author Étienne Germain
 * @file Corps.cpp
 * @date 17 janvier 2023
***/

#include "Corps.h"

Corps::Corps(Dynamixel2Arduino* dxl, int pin_electro, int id_moteur)
{
    moteur = new DXL_Corps(dxl, id_moteur, 0);
    ElectroCPU electro = ElectroCPU(pin_electro);      
    electroaimant = &electro;
    //electroaimant = new ElectroCPU(pin_electro);
}

Corps::~Corps()
{
    delete moteur;
    delete electroaimant;
}

void Corps::init()
{
    desactiverElectro();
    monter();

    monte = true;
    baisse = false;
}

bool Corps::monter()
{
    //completer le code

    monte = true;
    baisse = false;
}

bool Corps::baisser()
{
    //compléter le code

    monte = false;
    baisse = true;
}

void Corps::activerElectro()
{
    electroaimant->activer();
}

void Corps::desactiverElectro()
{
    electroaimant->desactiver();
}

bool Corps::estMonte()
{
    return monte;
}

bool Corps::estBaisse()
{
    return baisse;
}

bool Corps::electroActive()
{
    return electroaimant->getEtat();
}
