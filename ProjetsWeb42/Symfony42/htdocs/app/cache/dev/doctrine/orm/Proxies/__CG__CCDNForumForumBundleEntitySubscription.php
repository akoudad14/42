<?php

namespace Proxies\__CG__\CCDNForum\ForumBundle\Entity;

/**
 * DO NOT EDIT THIS FILE - IT WAS CREATED BY DOCTRINE'S PROXY GENERATOR
 */
class Subscription extends \CCDNForum\ForumBundle\Entity\Subscription implements \Doctrine\ORM\Proxy\Proxy
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
            return array('__isInitialized__', 'id', 'isRead', 'isSubscribed', 'forum', 'topic', 'ownedBy');
        }

        return array('__isInitialized__', 'id', 'isRead', 'isSubscribed', 'forum', 'topic', 'ownedBy');
    }

    /**
     * 
     */
    public function __wakeup()
    {
        if ( ! $this->__isInitialized__) {
            $this->__initializer__ = function (Subscription $proxy) {
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
    public function isRead()
    {

        $this->__initializer__ && $this->__initializer__->__invoke($this, 'isRead', array());

        return parent::isRead();
    }

    /**
     * {@inheritDoc}
     */
    public function setRead($isRead)
    {

        $this->__initializer__ && $this->__initializer__->__invoke($this, 'setRead', array($isRead));

        return parent::setRead($isRead);
    }

    /**
     * {@inheritDoc}
     */
    public function isSubscribed()
    {

        $this->__initializer__ && $this->__initializer__->__invoke($this, 'isSubscribed', array());

        return parent::isSubscribed();
    }

    /**
     * {@inheritDoc}
     */
    public function setSubscribed($isSubscribed)
    {

        $this->__initializer__ && $this->__initializer__->__invoke($this, 'setSubscribed', array($isSubscribed));

        return parent::setSubscribed($isSubscribed);
    }

    /**
     * {@inheritDoc}
     */
    public function getForum()
    {

        $this->__initializer__ && $this->__initializer__->__invoke($this, 'getForum', array());

        return parent::getForum();
    }

    /**
     * {@inheritDoc}
     */
    public function setForum(\CCDNForum\ForumBundle\Entity\Forum $forum = NULL)
    {

        $this->__initializer__ && $this->__initializer__->__invoke($this, 'setForum', array($forum));

        return parent::setForum($forum);
    }

    /**
     * {@inheritDoc}
     */
    public function getTopic()
    {

        $this->__initializer__ && $this->__initializer__->__invoke($this, 'getTopic', array());

        return parent::getTopic();
    }

    /**
     * {@inheritDoc}
     */
    public function setTopic(\CCDNForum\ForumBundle\Entity\Topic $topic = NULL)
    {

        $this->__initializer__ && $this->__initializer__->__invoke($this, 'setTopic', array($topic));

        return parent::setTopic($topic);
    }

    /**
     * {@inheritDoc}
     */
    public function getOwnedBy()
    {

        $this->__initializer__ && $this->__initializer__->__invoke($this, 'getOwnedBy', array());

        return parent::getOwnedBy();
    }

    /**
     * {@inheritDoc}
     */
    public function setOwnedBy(\Symfony\Component\Security\Core\User\UserInterface $ownedBy = NULL)
    {

        $this->__initializer__ && $this->__initializer__->__invoke($this, 'setOwnedBy', array($ownedBy));

        return parent::setOwnedBy($ownedBy);
    }

}
