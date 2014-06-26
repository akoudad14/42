<?php

namespace Proxies\__CG__\CCDNForum\ForumBundle\Entity;

/**
 * DO NOT EDIT THIS FILE - IT WAS CREATED BY DOCTRINE'S PROXY GENERATOR
 */
class Topic extends \CCDNForum\ForumBundle\Entity\Topic implements \Doctrine\ORM\Proxy\Proxy
{
    /**
     * @var \Closure the callback responsible for loading properties in the proxy object. This callback is called with
     *      three parameters, being respectively the proxy object to be initialized, the method that triggered the
     *      initialization process and an array of ordered parameters that were passed to that method.
     *
     * @see \Doctrine\Common\Persistence\Proxy::__setInitializer
     */
    public $__initializer__;

    /**
     * @var \Closure the callback responsible of loading properties that need to be copied in the cloned object
     *
     * @see \Doctrine\Common\Persistence\Proxy::__setCloner
     */
    public $__cloner__;

    /**
     * @var boolean flag indicating if this object was already initialized
     *
     * @see \Doctrine\Common\Persistence\Proxy::__isInitialized
     */
    public $__isInitialized__ = false;

    /**
     * @var array properties to be lazy loaded, with keys being the property
     *            names and values being their default values
     *
     * @see \Doctrine\Common\Persistence\Proxy::__getLazyProperties
     */
    public static $lazyPropertiesDefaults = array();



    /**
     * @param \Closure $initializer
     * @param \Closure $cloner
     */
    public function __construct($initializer = null, $cloner = null)
    {

        $this->__initializer__ = $initializer;
        $this->__cloner__      = $cloner;
    }







    /**
     * 
     * @return array
     */
    public function __sleep()
    {
        if ($this->__isInitialized__) {
            return array('__isInitialized__', 'id', 'title', 'cachedViewCount', 'cachedReplyCount', 'isClosed', 'closedDate', 'isDeleted', 'deletedDate', 'stickiedDate', 'isSticky', 'board', 'closedBy', 'deletedBy', 'stickiedBy', 'firstPost', 'lastPost', 'posts', 'subscriptions');
        }

        return array('__isInitialized__', 'id', 'title', 'cachedViewCount', 'cachedReplyCount', 'isClosed', 'closedDate', 'isDeleted', 'deletedDate', 'stickiedDate', 'isSticky', 'board', 'closedBy', 'deletedBy', 'stickiedBy', 'firstPost', 'lastPost', 'posts', 'subscriptions');
    }

    /**
     * 
     */
    public function __wakeup()
    {
        if ( ! $this->__isInitialized__) {
            $this->__initializer__ = function (Topic $proxy) {
                $proxy->__setInitializer(null);
                $proxy->__setCloner(null);

                $existingProperties = get_object_vars($proxy);

                foreach ($proxy->__getLazyProperties() as $property => $defaultValue) {
                    if ( ! array_key_exists($property, $existingProperties)) {
                        $proxy->$property = $defaultValue;
                    }
                }
            };

        }
    }

    /**
     * 
     */
    public function __clone()
    {
        $this->__cloner__ && $this->__cloner__->__invoke($this, '__clone', array());
    }

    /**
     * Forces initialization of the proxy
     */
    public function __load()
    {
        $this->__initializer__ && $this->__initializer__->__invoke($this, '__load', array());
    }

    /**
     * {@inheritDoc}
     * @internal generated method: use only when explicitly handling proxy specific loading logic
     */
    public function __isInitialized()
    {
        return $this->__isInitialized__;
    }

    /**
     * {@inheritDoc}
     * @internal generated method: use only when explicitly handling proxy specific loading logic
     */
    public function __setInitialized($initialized)
    {
        $this->__isInitialized__ = $initialized;
    }

    /**
     * {@inheritDoc}
     * @internal generated method: use only when explicitly handling proxy specific loading logic
     */
    public function __setInitializer(\Closure $initializer = null)
    {
        $this->__initializer__ = $initializer;
    }

    /**
     * {@inheritDoc}
     * @internal generated method: use only when explicitly handling proxy specific loading logic
     */
    public function __getInitializer()
    {
        return $this->__initializer__;
    }

    /**
     * {@inheritDoc}
     * @internal generated method: use only when explicitly handling proxy specific loading logic
     */
    public function __setCloner(\Closure $cloner = null)
    {
        $this->__cloner__ = $cloner;
    }

    /**
     * {@inheritDoc}
     * @internal generated method: use only when explicitly handling proxy specific cloning logic
     */
    public function __getCloner()
    {
        return $this->__cloner__;
    }

    /**
     * {@inheritDoc}
     * @internal generated method: use only when explicitly handling proxy specific loading logic
     * @static
     */
    public function __getLazyProperties()
    {
        return self::$lazyPropertiesDefaults;
    }

    
    /**
     * {@inheritDoc}
     */
    public function getId()
    {
        if ($this->__isInitialized__ === false) {
            return (int)  parent::getId();
        }


        $this->__initializer__ && $this->__initializer__->__invoke($this, 'getId', array());

        return parent::getId();
    }

    /**
     * {@inheritDoc}
     */
    public function getTitle()
    {

        $this->__initializer__ && $this->__initializer__->__invoke($this, 'getTitle', array());

        return parent::getTitle();
    }

    /**
     * {@inheritDoc}
     */
    public function setTitle($title)
    {

        $this->__initializer__ && $this->__initializer__->__invoke($this, 'setTitle', array($title));

        return parent::setTitle($title);
    }

    /**
     * {@inheritDoc}
     */
    public function getCachedViewCount()
    {

        $this->__initializer__ && $this->__initializer__->__invoke($this, 'getCachedViewCount', array());

        return parent::getCachedViewCount();
    }

    /**
     * {@inheritDoc}
     */
    public function setCachedViewCount($cachedViewCount)
    {

        $this->__initializer__ && $this->__initializer__->__invoke($this, 'setCachedViewCount', array($cachedViewCount));

        return parent::setCachedViewCount($cachedViewCount);
    }

    /**
     * {@inheritDoc}
     */
    public function getCachedReplyCount()
    {

        $this->__initializer__ && $this->__initializer__->__invoke($this, 'getCachedReplyCount', array());

        return parent::getCachedReplyCount();
    }

    /**
     * {@inheritDoc}
     */
    public function setCachedReplyCount($cachedReplyCount)
    {

        $this->__initializer__ && $this->__initializer__->__invoke($this, 'setCachedReplyCount', array($cachedReplyCount));

        return parent::setCachedReplyCount($cachedReplyCount);
    }

    /**
     * {@inheritDoc}
     */
    public function isClosed()
    {

        $this->__initializer__ && $this->__initializer__->__invoke($this, 'isClosed', array());

        return parent::isClosed();
    }

    /**
     * {@inheritDoc}
     */
    public function setClosed($isClosed)
    {

        $this->__initializer__ && $this->__initializer__->__invoke($this, 'setClosed', array($isClosed));

        return parent::setClosed($isClosed);
    }

    /**
     * {@inheritDoc}
     */
    public function getClosedDate()
    {

        $this->__initializer__ && $this->__initializer__->__invoke($this, 'getClosedDate', array());

        return parent::getClosedDate();
    }

    /**
     * {@inheritDoc}
     */
    public function setClosedDate($closedDate)
    {

        $this->__initializer__ && $this->__initializer__->__invoke($this, 'setClosedDate', array($closedDate));

        return parent::setClosedDate($closedDate);
    }

    /**
     * {@inheritDoc}
     */
    public function isDeleted()
    {

        $this->__initializer__ && $this->__initializer__->__invoke($this, 'isDeleted', array());

        return parent::isDeleted();
    }

    /**
     * {@inheritDoc}
     */
    public function setDeleted($isDeleted)
    {

        $this->__initializer__ && $this->__initializer__->__invoke($this, 'setDeleted', array($isDeleted));

        return parent::setDeleted($isDeleted);
    }

    /**
     * {@inheritDoc}
     */
    public function getDeletedDate()
    {

        $this->__initializer__ && $this->__initializer__->__invoke($this, 'getDeletedDate', array());

        return parent::getDeletedDate();
    }

    /**
     * {@inheritDoc}
     */
    public function setDeletedDate($deletedDate)
    {

        $this->__initializer__ && $this->__initializer__->__invoke($this, 'setDeletedDate', array($deletedDate));

        return parent::setDeletedDate($deletedDate);
    }

    /**
     * {@inheritDoc}
     */
    public function isSticky()
    {

        $this->__initializer__ && $this->__initializer__->__invoke($this, 'isSticky', array());

        return parent::isSticky();
    }

    /**
     * {@inheritDoc}
     */
    public function setSticky($isSticky)
    {

        $this->__initializer__ && $this->__initializer__->__invoke($this, 'setSticky', array($isSticky));

        return parent::setSticky($isSticky);
    }

    /**
     * {@inheritDoc}
     */
    public function getStickiedDate()
    {

        $this->__initializer__ && $this->__initializer__->__invoke($this, 'getStickiedDate', array());

        return parent::getStickiedDate();
    }

    /**
     * {@inheritDoc}
     */
    public function setStickiedDate($stickiedDate)
    {

        $this->__initializer__ && $this->__initializer__->__invoke($this, 'setStickiedDate', array($stickiedDate));

        return parent::setStickiedDate($stickiedDate);
    }

    /**
     * {@inheritDoc}
     */
    public function getBoard()
    {

        $this->__initializer__ && $this->__initializer__->__invoke($this, 'getBoard', array());

        return parent::getBoard();
    }

    /**
     * {@inheritDoc}
     */
    public function setBoard(\CCDNForum\ForumBundle\Entity\Board $board = NULL)
    {

        $this->__initializer__ && $this->__initializer__->__invoke($this, 'setBoard', array($board));

        return parent::setBoard($board);
    }

    /**
     * {@inheritDoc}
     */
    public function getClosedBy()
    {

        $this->__initializer__ && $this->__initializer__->__invoke($this, 'getClosedBy', array());

        return parent::getClosedBy();
    }

    /**
     * {@inheritDoc}
     */
    public function setClosedBy(\Symfony\Component\Security\Core\User\UserInterface $closedBy = NULL)
    {

        $this->__initializer__ && $this->__initializer__->__invoke($this, 'setClosedBy', array($closedBy));

        return parent::setClosedBy($closedBy);
    }

    /**
     * {@inheritDoc}
     */
    public function getDeletedBy()
    {

        $this->__initializer__ && $this->__initializer__->__invoke($this, 'getDeletedBy', array());

        return parent::getDeletedBy();
    }

    /**
     * {@inheritDoc}
     */
    public function setDeletedBy(\Symfony\Component\Security\Core\User\UserInterface $deletedBy = NULL)
    {

        $this->__initializer__ && $this->__initializer__->__invoke($this, 'setDeletedBy', array($deletedBy));

        return parent::setDeletedBy($deletedBy);
    }

    /**
     * {@inheritDoc}
     */
    public function getStickiedBy()
    {

        $this->__initializer__ && $this->__initializer__->__invoke($this, 'getStickiedBy', array());

        return parent::getStickiedBy();
    }

    /**
     * {@inheritDoc}
     */
    public function setStickiedBy(\Symfony\Component\Security\Core\User\UserInterface $stickiedBy = NULL)
    {

        $this->__initializer__ && $this->__initializer__->__invoke($this, 'setStickiedBy', array($stickiedBy));

        return parent::setStickiedBy($stickiedBy);
    }

    /**
     * {@inheritDoc}
     */
    public function getFirstPost()
    {

        $this->__initializer__ && $this->__initializer__->__invoke($this, 'getFirstPost', array());

        return parent::getFirstPost();
    }

    /**
     * {@inheritDoc}
     */
    public function setFirstPost(\CCDNForum\ForumBundle\Entity\Post $firstPost = NULL)
    {

        $this->__initializer__ && $this->__initializer__->__invoke($this, 'setFirstPost', array($firstPost));

        return parent::setFirstPost($firstPost);
    }

    /**
     * {@inheritDoc}
     */
    public function getLastPost()
    {

        $this->__initializer__ && $this->__initializer__->__invoke($this, 'getLastPost', array());

        return parent::getLastPost();
    }

    /**
     * {@inheritDoc}
     */
    public function setLastPost(\CCDNForum\ForumBundle\Entity\Post $lastPost = NULL)
    {

        $this->__initializer__ && $this->__initializer__->__invoke($this, 'setLastPost', array($lastPost));

        return parent::setLastPost($lastPost);
    }

    /**
     * {@inheritDoc}
     */
    public function getPosts()
    {

        $this->__initializer__ && $this->__initializer__->__invoke($this, 'getPosts', array());

        return parent::getPosts();
    }

    /**
     * {@inheritDoc}
     */
    public function setPosts(\Doctrine\Common\Collections\ArrayCollection $posts = NULL)
    {

        $this->__initializer__ && $this->__initializer__->__invoke($this, 'setPosts', array($posts));

        return parent::setPosts($posts);
    }

    /**
     * {@inheritDoc}
     */
    public function addPost(\CCDNForum\ForumBundle\Entity\Post $post)
    {

        $this->__initializer__ && $this->__initializer__->__invoke($this, 'addPost', array($post));

        return parent::addPost($post);
    }

    /**
     * {@inheritDoc}
     */
    public function removePost(\CCDNForum\ForumBundle\Entity\Post $post)
    {

        $this->__initializer__ && $this->__initializer__->__invoke($this, 'removePost', array($post));

        return parent::removePost($post);
    }

    /**
     * {@inheritDoc}
     */
    public function getSubscriptions()
    {

        $this->__initializer__ && $this->__initializer__->__invoke($this, 'getSubscriptions', array());

        return parent::getSubscriptions();
    }

    /**
     * {@inheritDoc}
     */
    public function setSubscriptions(\Doctrine\Common\Collections\ArrayCollection $subscriptions = NULL)
    {

        $this->__initializer__ && $this->__initializer__->__invoke($this, 'setSubscriptions', array($subscriptions));

        return parent::setSubscriptions($subscriptions);
    }

    /**
     * {@inheritDoc}
     */
    public function addSubscription(\CCDNForum\ForumBundle\Entity\Subscription $subscription)
    {

        $this->__initializer__ && $this->__initializer__->__invoke($this, 'addSubscription', array($subscription));

        return parent::addSubscription($subscription);
    }

    /**
     * {@inheritDoc}
     */
    public function removeSubscription(\CCDNForum\ForumBundle\Entity\Subscription $subscription)
    {

        $this->__initializer__ && $this->__initializer__->__invoke($this, 'removeSubscription', array($subscription));

        return parent::removeSubscription($subscription);
    }

}
