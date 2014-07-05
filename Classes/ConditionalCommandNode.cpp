//
//  ConditionalCommandNode.cpp
//  CthulfuLanguage
//
//  Created by Kazuki Oda on 2014/07/04.
//
//

#include "ConditionalCommandNode.h"
#include "CommandListNode.h"
#include "NumberCommandNode.h"
void ConditionalCommandNode::parse(Context *context) throw (CthulfuException) {
	while (true) {
		std::string current = context->getCurrentToken();
		if (current.compare("クトゥルフ・ダイクン！")  != 0 && current.compare("アザトース！") != 0 && current.compare("ヨグ・ソトース！") != 0) {
			break;
		}
		CCLOG("ーーーーー条件分岐：%s", current.c_str());
		context->skipToken(current);
		if (compare(context, current)) {
			mIsDone = true;
			Node *node = NULL;
			try {
				node = new CommandListNode();
				node->parse(context);
			}
			catch (const CthulfuException &e)
			{
				delete node;
				throw e;
			}
			delete node;
		}
		else {
			allSkip(context);
		}
	}
}

void ConditionalCommandNode::allSkip(Context *context) throw (CthulfuException) {
	CCLOG("全てのスキップを司ります");
	while (true) {
		if (context->hasNextToken()) {
			context->setNextToken();
			std::string token = context->getCurrentToken();
			CCLOG("スキップ:%s", token.c_str());
			if (token.compare("イア！イア！クトゥルフ＝フタグン！") == 0) {
				context->skipToken(token);
				CCLOG("スキップ終了しました");
				break;
			}
		}
	}
}

bool ConditionalCommandNode::compare(Context *context, const std::string &current) throw (CthulfuException) {
	if (current.compare("ヨグ・ソトース！") == 0) {
		CCLOG("輪がなはヨグソトース");
		return !mIsDone;
	}
	std::string condition = context->getCurrentToken();
	CCLOG("これから比較致します");
	context->skipToken(condition);
	NumberCommandNode *numNode = new NumberCommandNode();
	int num = 0;
	int memoryNum = context->getMemoryNum();
	try {
		numNode->parse(context);
		num = numNode->getNumber();
		delete numNode;
	}
	catch (const CthulfuException &e)
	{
		delete numNode;
		throw e;
	}

	if (condition.compare("ネブロッド・ヅイン！ネブロッド・ヅイン！") == 0) {
		return memoryNum > num;
	}
	else if (condition.compare("ヤール・ムテン！ダクタリンカ・フタグン！") == 0) {
		return memoryNum < num;
	}
	else if (condition.compare("シュブ・ニグラス！") == 0) {
		return memoryNum == num;
	}
	else if (condition.compare("フングルイ＝ムグルウナフ！ウガ＝ナグル・フタグン !") == 0) {
		return memoryNum != num;
	}
	else {
		CCLOG("何やらおかしなものが呼ばれて比較などできませんでした(%s)", condition.c_str());
		throw CthulfuException();
	}
	return false;
}
