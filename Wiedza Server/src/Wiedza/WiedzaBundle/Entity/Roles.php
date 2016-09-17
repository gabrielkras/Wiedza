<?php
/**
 * User: gabrielkras
 * Date: 21/08/16
 * Time: 19:15
 */

namespace Wiedza\WiedzaBundle\Entity;

use Doctrine\Common\Collections\ArrayCollection;
use Doctrine\ORM\Mapping as ORM;
use Symfony\Component\Security\Core\Role\RoleInterface;
use Symfony\Component\Validator\Constraints\DateTime;

/**
 * Class Roles
 * @package Wiedza\WiedzaBundle\Entity
 *
 * @ORM\Table(name="roles")
 * @ORM\Entity()
 */
class Roles implements RoleInterface
{
    const TYPE_ROLE_ADMIN        = 0;
    const TYPE_ROLE_STUDENT      = 1;
    const TYPE_ROLE_TEACHER      = 2;
    const TYPE_ROLE_FUNCTIONARY  = 3;

    /**
     * @ORM\Column(name="id", type="integer")
     * @ORM\Id()
     * @ORM\GeneratedValue(strategy="AUTO")
     */
    private $id;

    /**
     * @ORM\ManyToMany(targetEntity="Wiedza\WiedzaBundle\Entity\Login", mappedBy="roles")
     */
    private $login;
    /**
     * @ORM\Column(name="type", type="integer")
     */
    private $type;

    /**
     * @ORM\Column(name="role", type="string", length=32)
     */
    private $role;

    /**
     * @ORM\Column(name="created", type="datetime")
     */
    private $created;

    /**
     * Roles constructor.
     */
    public function __construct()
    {
        $this->created = new \DateTime('now');
        $this->login = new ArrayCollection();
    }

    /**
     * @return String
     */
    public function getRole()
    {
        return $this->role;
    }

    /**
     * @return integer
     */
    public function getId()
    {
        return $this->id;
    }

    /**
     * @return ArrayCollection
     */
    public function getLogin()
    {
        return $this->login;
    }

    /**
     * @return integer
     */
    public function getType()
    {
        return $this->type;
    }

    /**
     * @return DateTime
     */
    public function getCreated()
    {
        return $this->created;
    }

    /**
     * @param Login $login
     */
    public function addLogin(Login $login)
    {
        $this->login->add($login);
    }

    /**
     * @param Login $login
     */
    public function removeLogin(Login $login)
    {
        $this->login->remove($login);
    }

    /**
     * @param $type
     */
    public function setType($type)
    {
        $this->type = $type;
    }

    /**
     * @param $role
     */
    public function setRole($role)
    {
        $this->role = $role;
    }

}