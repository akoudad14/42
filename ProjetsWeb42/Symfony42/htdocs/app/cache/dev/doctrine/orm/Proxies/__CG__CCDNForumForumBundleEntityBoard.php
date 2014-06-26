<?php

namespace Proxies\__CG__\CCDNForum\ForumBundle\Entity;

/**
 * DO NOT EDIT THIS FILE - IT WAS CREATED BY DOCTRINE'S PROXY GENERATOR
 */
class Board extends \CCDNForum\ForumBundle\Entity\Board implements \Doctrine\ORM\Proxy\Proxy
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
            return array('__isInitialized__', 'id', 'name', 'description', 'cachedTopicCount', 'cachedPostCount', 'listOrderPriority', 'readAuthorisedRoles', 'topicCreateAuthorisedRoles', 'topicReplyAuthorisedRoles', 'category', 'topics', 'lastPost');
        }

        return array('__isInitialized__', 'id', 'name', 'description', 'cachedTopicCount', 'cachedPostCount', 'listOrderPriority', 'readAuthorisedRoles', 'topicCreateAuthorisedRoles', 'topicReplyAuthorisedRoles', 'category', 'topics', 'lastPost');
    }

    /**
     * 
     */
    public function __wakeup()
    {
        if ( ! $this->__isInitialized__) {
            $this->__initializer__ = function (Board $proxy) {
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
    public function __toString()
    {

        $this->__initializer__ && $this->__initializer__->__invoke($this, '__toString', array());

        return parent::__toString();
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
    public function getName()
    {

        $this->__initializer__ && $this->__initializer__->__invoke($this, 'getName', array());

        return parent::getName();
    }

    /**
     * {@inheritDoc}
     */
    public function setName($name)
    {

        $this->__initializer__ && $this->__initializer__->__invoke($this, 'setName', array($name));

        return parent::setName($name);
    }

    /**
     * {@inheritDoc}
     */
    public function getDescription()
    {

        $this->__initializer__ && $this->__initializer__->__invoke($this, 'getDescription', array());

        return parent::getDescription();
    }

    /**
     * {@inheritDoc}
     */
    public function setDescription($description)
    {

        $this->__initializer__ && $this->__initializer__->__invoke($this, 'setDescription', array($description));

        return parent::setDescription($description);
    }

    /**
     * {@inheritDoc}
     */
    public function getListOrderPriority()
    {

        $this->__initializer__ && $this->__initializer__->__invoke($this, 'getListOrderPriority', array());

        return parent::getListOrderPriority();
    }

    /**
     * {@inheritDoc}
     */
    public function setListOrderPriority($listOrderPriority)
    {

        $this->__initializer__ && $this->__initializer__->__invoke($this, 'setListOrderPriority', array($listOrderPriority));

        return parent::setListOrderPriority($listOrderPriority);
    }

    /**
     * {@inheritDoc}
     */
    public function getCachedTopicCount()
    {

        $this->__initializer__ && $this->__initializer__->__invoke($this, 'getCachedTopicCount', array());

        return parent::getCachedTopicCount();
    }

    /**
     * {@inheritDoc}
     */
    public function setCachedTopicCount($cachedTopicCount)
    {

        $this->__initializer__ && $this->__initializer__->__invoke($this, 'setCachedTopicCount', array($cachedTopicCount));

        return parent::setCachedTopicCount($cachedTopicCount);
    }

    /**
     * {@inheritDoc}
     */
    public function getCachedPostCount()
    {

        $this->__initializer__ && $this->__initializer__->__invoke($this, 'getCachedPostCount', array());

        return parent::getCachedPostCount();
    }

    /**
     * {@inheritDoc}
     */
    public function setCachedPostCount($cachedPostCount)
    {

        $this->__initializer__ && $this->__initializer__->__invoke($this, 'setCachedPostCount', array($cachedPostCount));

        return parent::setCachedPostCount($cachedPostCount);
    }

    /**
     * {@inheritDoc}
     */
    public function getReadAuthorisedRoles()
    {

        $this->__initializer__ && $this->__initializer__->__invoke($this, 'getReadAuthorisedRoles', array());

        return parent::getReadAuthorisedRoles();
    }

    /**
     * {@inheritDoc}
     */
    public function setReadAuthorisedRoles(array $roles = NULL)
    {

        $this->__initializer__ && $this->__initializer__->__invoke($this, 'setReadAuthorisedRoles', array($roles));

        return parent::setReadAuthorisedRoles($roles);
    }

    /**
     * {@inheritDoc}
     */
    public function hasReadAuthorisedRole($role)
    {

        $this->__initializer__ && $this->__initializer__->__invoke($this, 'hasReadAuthorisedRole', array($role));

        return parent::hasReadAuthorisedRole($role);
    }

    /**
     * {@inheritDoc}
     */
    public function isAuthorisedToRead(\Symfony\Component\Security\Core\SecurityContextInterface $securityContext)
    {

        $this->__initializer__ && $this->__initializer__->__invoke($this, 'isAuthorisedToRead', array($securityContext));

        return parent::isAuthorisedToRead($securityContext);
    }

    /**
     * {@inheritDoc}
     */
    public function getTopicCreateAuthorisedRoles()
    {

        $this->__initializer__ && $this->__initializer__->__invoke($this, 'getTopicCreateAuthorisedRoles', array());

        return parent::getTopicCreateAuthorisedRoles();
    }

    /**
     * {@inheritDoc}
     */
    public function setTopicCreateAuthorisedRoles(array $roles = NULL)
    {

        $this->__initializer__ && $this->__initializer__->__invoke($this, 'setTopicCreateAuthorisedRoles', array($roles));

        return parent::setTopicCreateAuthorisedRoles($roles);
    }

    /**
     * {@inheritDoc}
     */
    public function hasTopicCreateAuthorisedRole($role)
    {

        $this->__initializer__ && $this->__initializer__->__invoke($this, 'hasTopicCreateAuthorisedRole', array($role));

        return parent::hasTopicCreateAuthorisedRole($role);
    }

    /**
     * {@inheritDoc}
     */
    public function isAuthorisedToCreateTopic(\Symfony\Component\Security\Core\SecurityContextInterface $securityContext)
    {

        $this->__initializer__ && $this->__initializer__->__invoke($this, 'isAuthorisedToCreateTopic', array($securityContext));

        return parent::isAuthorisedToCreateTopic($securityContext);
    }

    /**
     * {@inheritDoc}
     */
    public function getTopicReplyAuthorisedRoles()
    {

        $this->__initializer__ && $this->__initializer__->__invoke($this, 'getTopicReplyAuthorisedRoles', array());

        return parent::getTopicReplyAuthorisedRoles();
    }

    /**
     * {@inheritDoc}
     */
    public function setTopicReplyAuthorisedRoles(array $roles = NULL)
    {

        $this->__initializer__ && $this->__initializer__->__invoke($this, 'setTopicReplyAuthorisedRoles', array($roles));

        return parent::setTopicReplyAuthorisedRoles($roles);
    }

    /**
     * {@inheritDoc}
     */
    public function hasTopicReplyAuthorisedRole($role)
    {

        $this->__initializer__ && $this->__initializer__->__invoke($this, 'hasTopicReplyAuthorisedRole', array($role));

        return parent::hasTopicReplyAuthorisedRole($role);
    }

    /**
     * {@inheritDoc}
     */
    public function isAuthorisedToReplyToTopic(\Symfony\Component\Security\Core\SecurityContextInterface $securityContext)
    {

        $this->__initializer__ && $this->__initializer__->__invoke($this, 'isAuthorisedToReplyToTopic', array($securityContext));

        return parent::isAuthorisedToReplyToTopic($securityContext);
    }

    /**
     * {@inheritDoc}
     */
    public function getCategory()
    {

        $this->__initializer__ && $this->__initializer__->__invoke($this, 'getCategory', array());

        return parent::getCategory();
    }

    /**
     * {@inheritDoc}
     */
    public function setCategory(\CCDNForum\ForumBundle\Entity\Category $category = NULL)
    {

        $this->__initializer__ && $this->__initializer__->__invoke($this, 'setCategory', array($category));

        return parent::setCategory($category);
    }

    /**
     * {@inheritDoc}
     */
    public function getTopics()
    {

        $this->__initializer__ && $this->__initializer__->__invoke($this, 'getTopics', array());

        return parent::getTopics();
    }

    /**
     * {@inheritDoc}
     */
    public function setTopics(\Doctrine\Common\Collections\ArrayCollection $topics = NULL)
    {

        $this->__initializer__ && $this->__initializer__->__invoke($this, 'setTopics', array($topics));

        return parent::setTopics($topics);
    }

    /**
     * {@inheritDoc}
     */
    public function addTopic(\CCDNForum\ForumBundle\Entity\Topic $topic)
    {

        $this->__initializer__ && $this->__initializer__->__invoke($this, 'addTopic', array($topic));

        return parent::addTopic($topic);
    }

    /**
     * {@inheritDoc}
     */
    public function removeTopic(\CCDNForum\ForumBundle\Entity\Topic $topic)
    {

        $this->__initializer__ && $this->__initializer__->__invoke($this, 'removeTopic', array($topic));

        return parent::removeTopic($topic);
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
    public function setLastPost($lastPost = NULL)
    {

        $this->__initializer__ && $this->__initializer__->__invoke($this, 'setLastPost', array($lastPost));

        return parent::setLastPost($lastPost);
    }

}
