//
//  CommandListNode.cpp
//  CthulfuLanguage
//
//  Created by Kazuki Oda on 2014/07/04.
//
//

#include "CommandListNode.h"
#include "CommandNode.h"
void CommandListNode::parse(Context *context) throw (CthulfuException) {
	int count = 0;
	while (true) {
		count++;
		CCLOG("【ターン%d】", count);
		std::string token = context->getCurrentToken();
		if (token.compare("イア！イア！クトゥルフ＝フタグン！") == 0) {
			context->skipToken(token);
			CCLOG("帰還の呪文が呼ばれました:%s", token.c_str());
			break;
		}
		else if (token.compare("フングルイムグルウナフ！クトゥルフ！ルル・イエー・ウガ＝ナグル・フタグン！") == 0) {
			CCLOG("大いなる帰還の呪文が呼ばれました:%s", token.c_str());
			while (context->hasNextToken()) {
				context->setNextToken();
			}
			break;
		}
		else if (!context->hasNextToken()) {
			CCLOG("帰還の呪文が呼ばれませんでした。");
			throw CthulfuException();
		}
		else {
			Node *command = new CommandNode();
			try {
				command->parse(context);
				delete command;
			}
			catch (const CthulfuException &e)
			{
				CCLOG("次なる召還に失敗しました");
				delete command;
				throw e;
			}
		}
		if (count > 1000) {
			CCLOG("無限ループに陥っている気が");
			throw CthulfuException();
		}
	}
}
