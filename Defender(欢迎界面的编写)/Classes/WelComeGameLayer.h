#ifndef __WELCOMEGAME_LAYER_H__
#define __WELCOMEGAME_LAYER_H__
#include "BaseLayer.h"
class WelComeGameLayer:public BaseLayer{
public:
	static cocos2d::CCScene* scene();
	virtual bool init();
	CREATE_FUNC(WelComeGameLayer);
	virtual void onEnter();
private:
	// s���ý���
	bool setUpdateView();
	// ���Ż�����ͣ���ֻص�����
	void vedioOnAndOffCallBack(cocos2d::CCObject* pSend);
	// ��ת�� ���ڿ����߽���Ļص�����
	void menuCoderCallback(cocos2d::CCObject* pSend);

};
#endif