#pragma once
#ifndef FUNCTION_H
#define FUNCTION_H
#include "wujiangmanage.h"
#include"wujiang.h"
char menu();
void doAddWujiang(WujiangManage& cm);
void doRemoveWujiang(WujiangManage& cm);
void doViewWujiang(const WujiangManage& cm);
void doViewAllWujiangs(const WujiangManage& cm);
void doModifyWujiangInfo(WujiangManage& cm);
void doStartWar(WujiangManage& cm);
int chooseFindMethod();
#endif // FUNCTION_H