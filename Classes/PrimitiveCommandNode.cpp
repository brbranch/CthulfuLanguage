//
//  PrimitiveCommandNode.cpp
//  CthulfuLanguage
//
//  Created by Kazuki Oda on 2014/07/04.
//
//

#include "PrimitiveCommandNode.h"
#include "NumberCommandNode.h"
#include "cocos2d.h"
void PrimitiveCommandNode::parse(Context *context) throw (CthulfuException) {
	std::string current = context->getCurrentToken();
	CCLOG("ただいまより%sが行動をおこします", current.c_str());
	if (current.compare("クトゥルフ・フタグン！ニャルラトホテップ・ツガー！シャメッシュ！シャメッシュ！") == 0) {
		//charの配列(list)を初期化する
		context->skipToken(current);
		std::list <char> *list = context->getCharList();
		CCLOG("ーーーーー文字は初期化された");
		list->clear();
	}
	else if (current.compare("イアール・ムナール！ウガ＝ナグル・トナロロ・ヨナラナーク・シラーリー！") == 0) {
		//charの配列でログ出力する
		context->skipToken(current);
		char *pChar = createChar(context);
		CCLOG("ーーーーー声が聞こえる。");
		CCLOG("「%s」", pChar);
		delete[] pChar;
	}
	else if (current.compare("ヤイ・ングナガ！ヨグ・ソトホース！ヘエ＝ルゲブ！ファイ・サロドグ・ウアフ！") == 0) {
		context->skipToken(current);
		int num = getNum(context);
		if (context->getLabel()) {
			context->getLabel()->setFontSize(num);
		}
		CCLOG("ーーーーー文字の大きさが変更された:%d", num);
	}
	else if (current.compare("ウザ・イエイ！ウザ・イエイ！イカア・ハ・ブホウイイ！ラアン＝テゴス！クトゥルフ・フタグン！") == 0) {
		context->skipToken(current);
		char *pChar = createChar(context);
		if (context->getLabel()) {
			context->getLabel()->setString(pChar);
		}
		CCLOG("ーーーーー文字が設定された:%s", pChar);
		delete[] pChar;
	}
	else if (current.compare("イア！イア！ハスタア！ハスタア・クフアヤク＝ブルグトム・ブグトラグルン！ブルグトム！") == 0) {
		context->skipToken(current);
		int num = getNum(context);
		float duration = num * 0.1f;
		float scale = getNum(context) * 0.1f;
		if (context->getActions()) {
			context->getActions()->addObject(cocos2d::CCScaleTo::create(duration, scale));
			context->getActions()->addObject(cocos2d::CCScaleTo::create(duration, 1.0f));
		}
		CCLOG("ーーーーー文字は伸縮するだろう(大きさ:%f 時間:%f)", duration, scale);
	}
	else if (current.compare("オング・ダクタ・リンカ！ネブロッド・ヅイン！ネブロッド・ヅイン！オング・ダクタ・リンカ！") == 0) {
		context->skipToken(current);
		int num2 = getNum(context);
		int num = getNum(context);
		if (context->getActions()) {
			context->getActions()->addObject(cocos2d::CCJumpBy::create(1.0f, ccp(0, 0), num, num2));
		}
		CCLOG("ーーーーー文字は飛び跳ねるだろう(%d %d)", num, num2);
	}
	else if (current.compare("ヘイ・アア＝シャンタ・ナイグ！") == 0) {
		context->skipToken(current);
		int num2 = getNum(context);
		int num = getNum(context);
		if (context->getActions()) {
			context->getActions()->addObject(cocos2d::CCRotateBy::create(num2 * 0.1f, num));
		}
		CCLOG("ーーーーー文字は回転するだろう(%d)", num);
	}
	else if (current.compare("イア・ル・リェー！クトゥルフ・フタグン！イア！イア！") == 0) {
		context->skipToken(current);
		int num = getNum(context);
		int num2 = getNum(context);
		int num3 = getNum(context);
		if (context->getActions()) {
			context->getActions()->addObject(cocos2d::CCMoveBy::create(num * 0.1f, ccp(num2, num3)));
		}
		CCLOG("ーーーーー文字は動くだろう(%f , %d , %d)", num * 0.1f, num2, num3);
	}
	else if (current.compare("オグトロド・アイ・フ！ゲブル＝エエヘ！ヨグ・ソトト・ンガーング！アイイ・ズロー！") == 0) {
		context->skipToken(current);
		int num = getNum(context);
		if (context->getActions()) {
			context->getActions()->addObject(cocos2d::CCDelayTime::create(num * 0.1f));
		}
		CCLOG("ーーーーー画面は止まるだろう:%f", num * 0.1f);
	}
	else if (current.compare("ニャルラトホテップ・ツガー！") == 0) {
		context->skipToken(current);
		int num = getNum(context);
		context->setMemoryNum(num);
		CCLOG("ーーーーーメモリに数字が保存された:%d", num);
	}
	else if (current.compare("イア！イア！") == 0) {
		int num = getNum(context);
		CCLOG("ーーーーー無駄に数字が呼ばれた:%d", num);
	}
	else if (current.find_first_of("#") == 0) {
		CCLOG("コメント:%s", current.c_str());
		context->skipToken(current);
	}
	else {
		context->skipToken(current);
		if (context->getCurrentToken().compare("イア！イア！") == 0) {
			int num = getNum(context);
			std::list <char> *list = context->getCharList();
			CCLOG("ーーーーー文字%cが加えられた", num);
			list->push_back(num);
		}
		else {
			int num = context->getMemoryNum();
			std::list <char> *list = context->getCharList();
			CCLOG("ーーーーーメモリの数字を使って文字%cが加えられた", num);
			list->push_back(num);
		}
	}
}

char *PrimitiveCommandNode::createChar(Context *context) {
	std::list <char> *list = context->getCharList();
	int size = list->size();
	CCLOG("size:%d", size);
	char *str = new char[size + 1];
	std::list <char>::iterator it;
	int i = 0;
	for (it = list->begin(); it != list->end(); it++) {
		str[i] = *it;
		i++;
	}
	str[i] = '\0';
	return str;
}

int PrimitiveCommandNode::getNum(Context *context) throw (CthulfuException) {
	NumberCommandNode *num = NULL;
	try {
		num = new NumberCommandNode();
		num->parse(context);
		int nums = num->getNumber();
		delete num;
		return nums;
	}
	catch (const CthulfuException &e)
	{
		CCLOG("数値は拒絶された");
		delete num;
		throw e;
	}
}
