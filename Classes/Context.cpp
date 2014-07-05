//
//  Context.cpp
//  CthulfuLanguage
//
//  Created by Kazuki Oda on 2014/07/04.
//
//

#include "Context.h"
#include "cocos2d.h"
#define CONTEXT_DELIMITER " \n\r\t"

bool Context::setNextToken() {
	if (!hasNextToken()) {
		CCLOG("Context::setNetToken()::Token is End");
		return false;
	}
	else {
		mIndex++;
		CCLOG("Context::setNetToken()");
		return true;
	}
}

bool Context::hasNextToken() {
	return mTokenList.size() >= mIndex;
}

std::string Context::getCurrentToken() {
	return mTokenList.at(mIndex);
}

void Context::skipToken(const std::string &token) throw (CthulfuException) {
	if (getCurrentToken().compare(token) != 0) {
		CCLOG("スキップできない者がスキップされた%s(%s)", getCurrentToken().c_str(), token.c_str());
		CCLOG("-------窓に！窓に！");
		throw CthulfuException();
	}
	CCLOG("%sはスキップされました。", getCurrentToken().c_str());
	this->setNextToken();
}

void Context::execute(cocos2d::CCNode *node) {
	if (mLabel != NULL) {
		node->addChild(mLabel);
		if (mActions != NULL && mActions->count() > 0) {
			mLabel->runAction(cocos2d::CCSequence::create(mActions));
			mActions->release();
			mActions = NULL;
		}
		mLabel->release();
		mLabel = NULL;
	}
	else {
		CCLOG("CCLabelTTFが召還されてません。");
	}
}

void Context::createCCLabelTTF() {
	if (mLabel != NULL) {
		mLabel->release();
		mLabel = NULL;
	}
	mLabel = cocos2d::CCLabelTTF::create("empty", "Alias", 10.f);
	mLabel->setColor(cocos2d::ccc3(255, 255, 255));
	mLabel->setPosition(cocos2d::CCDirector::sharedDirector()->getVisibleSize() / 2);
	mLabel->retain();

	if (mActions != NULL) {
		mActions->release();
		mActions = NULL;
	}
	mActions = cocos2d::CCArray::create();
	mActions->retain();
}

Context::Context(const char *text) {
	CCLOG("Context:create");
	mActions = NULL;
	mLabel = NULL;
	mMemoryNum = 0;
	mIndex = 0;

	char _text[1024 * 20];
	strcpy(_text, text);
	char *tmp;
	tmp = std::strtok(_text, CONTEXT_DELIMITER);
	mTokenList.push_back(tmp);
	CCLOG("strtok:%s", tmp);
	while (tmp != NULL) {
		tmp = std::strtok(NULL, CONTEXT_DELIMITER);
		if (tmp != NULL) {
			CCLOG("strtok:%s", tmp);
			mTokenList.push_back(tmp);
		}
	}
	CCLOG("要素数:%lu", mTokenList.size());
}

Context::~Context() {
	CCLOG("Context:delete");
	CC_SAFE_RELEASE_NULL(mLabel);
	CC_SAFE_RELEASE_NULL(mActions);
}
