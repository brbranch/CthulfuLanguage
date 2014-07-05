//
//  ProgramNode.cpp
//  CthulfuLanguage
//
//  Created by Kazuki Oda on 2014/07/04.
//
//

#include "ProgramNode.h"
#include "CommandListNode.h"
void ProgramNode::parse(Context *context) throw (CthulfuException) {
	context->skipToken("フングルイムグルウナフ！クトゥルフ！フォマルハウト・ンガア・グア！ナフルタグン！イア！クトゥグア！");
	CCLOG("呪文が唱えられました。ただいまより召還に入ります");
	context->createCCLabelTTF();
	Node *listNode = new CommandListNode();
	try {
		listNode->parse(context);
		delete listNode;
	}
	catch (const CthulfuException &e)
	{
		delete listNode;
		CCLOG("CommandListNode:エラーになりました");
		throw e;
	}
}
