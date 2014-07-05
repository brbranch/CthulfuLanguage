//
//  CommandNode.cpp
//  CthulfuLanguage
//
//  Created by Kazuki Oda on 2014/07/04.
//
//

#include "CommandNode.h"
void CommandNode::parse(Context *context) throw (CthulfuException) {
	Node *node = NULL;
	CCLOG("次なる行動を開始します");
	try {
		if (context->getCurrentToken().compare("ティビ・マグヌム・イノミナンドゥム・シグナ！ステラルム！イグラルム！エブファニフォルミス！") == 0) {
			//リピート
			node = new RepeatCommandNode();
		}
		else if (context->getCurrentToken().compare("クトゥルフ・ダイクン！") == 0) {
			//条件分岐
			node = new ConditionalCommandNode();
		}
		else {
			//その他コマンド
			node = new PrimitiveCommandNode();
		}
		node->parse(context);
		delete node;
		CCLOG("次なる行動終了");
	}
	catch (const CthulfuException &e)
	{
		if (node != NULL) {
			delete node;
		}
		CCLOG("次なる行動でエラーがおきました");
		throw e;
	}
}
