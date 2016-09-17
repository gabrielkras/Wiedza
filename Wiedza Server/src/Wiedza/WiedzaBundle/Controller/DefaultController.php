<?php

namespace Wiedza\WiedzaBundle\Controller;

use Symfony\Bundle\FrameworkBundle\Controller\Controller;

class DefaultController extends Controller
{
    public function indexAction()
    {
        return $this->render('WiedzaBundle:Default:index.html.twig');
    }
}
