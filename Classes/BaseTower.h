#ifndef  _BASE_TOWER_H_
#define  _BASE_TOWER_H_

#include "cocos2d.h"
#include "BaseMonster.h"

class BaseTower :
	public cocos2d::Layer
{
	CC_SYNTHESIZE(int, _scope, Scope);
	CC_SYNTHESIZE(float, _shootIntervalTime, ShootIntervalTime);

	virtual void shootBullet(float dt) = 0;

protected:

	BaseTower();
	bool searchTarget();

protected:
	BaseMonster *_nearestMonster;
};

class BaseBullet :
	public cocos2d::Layer
{
public:

	CC_SYNTHESIZE(int, _lethality, Lethality);
	void setOrigin(const cocos2d::Vec2 &origin);
	const cocos2d::Vec2& getOrigin() const;
	void setDirection(const cocos2d::Vec2 &direction);
	const cocos2d::Vec2& getDirection() const;
	void setVelocity(float velocity);
	float getVelocity();
	void setShootRange(float range);
	float getShootRange();
	bool isOutOfBound();

	void fillBulletTo(cocos2d::Node *node);
	void shoot(bool rotByDir = false);
	bool hitTarget(cocos2d::Node *target);
	void removeBullet();

protected:

	BaseBullet();

protected:

	cocos2d::Vec2 _origin;
	cocos2d::Vec2 _direction;
	float _velocity;
	float _shootRange;
};

#endif