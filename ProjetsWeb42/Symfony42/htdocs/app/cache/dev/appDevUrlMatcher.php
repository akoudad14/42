<?php

use Symfony\Component\Routing\Exception\MethodNotAllowedException;
use Symfony\Component\Routing\Exception\ResourceNotFoundException;
use Symfony\Component\Routing\RequestContext;

/**
 * appDevUrlMatcher
 *
 * This class has been auto-generated
 * by the Symfony Routing Component.
 */
class appDevUrlMatcher extends Symfony\Bundle\FrameworkBundle\Routing\RedirectableUrlMatcher
{
    /**
     * Constructor.
     */
    public function __construct(RequestContext $context)
    {
        $this->context = $context;
    }

    public function match($pathinfo)
    {
        $allow = array();
        $pathinfo = rawurldecode($pathinfo);
        $context = $this->context;
        $request = $this->request;

        if (0 === strpos($pathinfo, '/_')) {
            // _wdt
            if (0 === strpos($pathinfo, '/_wdt') && preg_match('#^/_wdt/(?P<token>[^/]++)$#s', $pathinfo, $matches)) {
                return $this->mergeDefaults(array_replace($matches, array('_route' => '_wdt')), array (  '_controller' => 'web_profiler.controller.profiler:toolbarAction',));
            }

            if (0 === strpos($pathinfo, '/_profiler')) {
                // _profiler_home
                if (rtrim($pathinfo, '/') === '/_profiler') {
                    if (substr($pathinfo, -1) !== '/') {
                        return $this->redirect($pathinfo.'/', '_profiler_home');
                    }

                    return array (  '_controller' => 'web_profiler.controller.profiler:homeAction',  '_route' => '_profiler_home',);
                }

                if (0 === strpos($pathinfo, '/_profiler/search')) {
                    // _profiler_search
                    if ($pathinfo === '/_profiler/search') {
                        return array (  '_controller' => 'web_profiler.controller.profiler:searchAction',  '_route' => '_profiler_search',);
                    }

                    // _profiler_search_bar
                    if ($pathinfo === '/_profiler/search_bar') {
                        return array (  '_controller' => 'web_profiler.controller.profiler:searchBarAction',  '_route' => '_profiler_search_bar',);
                    }

                }

                // _profiler_purge
                if ($pathinfo === '/_profiler/purge') {
                    return array (  '_controller' => 'web_profiler.controller.profiler:purgeAction',  '_route' => '_profiler_purge',);
                }

                if (0 === strpos($pathinfo, '/_profiler/i')) {
                    // _profiler_info
                    if (0 === strpos($pathinfo, '/_profiler/info') && preg_match('#^/_profiler/info/(?P<about>[^/]++)$#s', $pathinfo, $matches)) {
                        return $this->mergeDefaults(array_replace($matches, array('_route' => '_profiler_info')), array (  '_controller' => 'web_profiler.controller.profiler:infoAction',));
                    }

                    // _profiler_import
                    if ($pathinfo === '/_profiler/import') {
                        return array (  '_controller' => 'web_profiler.controller.profiler:importAction',  '_route' => '_profiler_import',);
                    }

                }

                // _profiler_export
                if (0 === strpos($pathinfo, '/_profiler/export') && preg_match('#^/_profiler/export/(?P<token>[^/\\.]++)\\.txt$#s', $pathinfo, $matches)) {
                    return $this->mergeDefaults(array_replace($matches, array('_route' => '_profiler_export')), array (  '_controller' => 'web_profiler.controller.profiler:exportAction',));
                }

                // _profiler_phpinfo
                if ($pathinfo === '/_profiler/phpinfo') {
                    return array (  '_controller' => 'web_profiler.controller.profiler:phpinfoAction',  '_route' => '_profiler_phpinfo',);
                }

                // _profiler_search_results
                if (preg_match('#^/_profiler/(?P<token>[^/]++)/search/results$#s', $pathinfo, $matches)) {
                    return $this->mergeDefaults(array_replace($matches, array('_route' => '_profiler_search_results')), array (  '_controller' => 'web_profiler.controller.profiler:searchResultsAction',));
                }

                // _profiler
                if (preg_match('#^/_profiler/(?P<token>[^/]++)$#s', $pathinfo, $matches)) {
                    return $this->mergeDefaults(array_replace($matches, array('_route' => '_profiler')), array (  '_controller' => 'web_profiler.controller.profiler:panelAction',));
                }

                // _profiler_router
                if (preg_match('#^/_profiler/(?P<token>[^/]++)/router$#s', $pathinfo, $matches)) {
                    return $this->mergeDefaults(array_replace($matches, array('_route' => '_profiler_router')), array (  '_controller' => 'web_profiler.controller.router:panelAction',));
                }

                // _profiler_exception
                if (preg_match('#^/_profiler/(?P<token>[^/]++)/exception$#s', $pathinfo, $matches)) {
                    return $this->mergeDefaults(array_replace($matches, array('_route' => '_profiler_exception')), array (  '_controller' => 'web_profiler.controller.exception:showAction',));
                }

                // _profiler_exception_css
                if (preg_match('#^/_profiler/(?P<token>[^/]++)/exception\\.css$#s', $pathinfo, $matches)) {
                    return $this->mergeDefaults(array_replace($matches, array('_route' => '_profiler_exception_css')), array (  '_controller' => 'web_profiler.controller.exception:cssAction',));
                }

            }

            if (0 === strpos($pathinfo, '/_configurator')) {
                // _configurator_home
                if (rtrim($pathinfo, '/') === '/_configurator') {
                    if (substr($pathinfo, -1) !== '/') {
                        return $this->redirect($pathinfo.'/', '_configurator_home');
                    }

                    return array (  '_controller' => 'Sensio\\Bundle\\DistributionBundle\\Controller\\ConfiguratorController::checkAction',  '_route' => '_configurator_home',);
                }

                // _configurator_step
                if (0 === strpos($pathinfo, '/_configurator/step') && preg_match('#^/_configurator/step/(?P<index>[^/]++)$#s', $pathinfo, $matches)) {
                    return $this->mergeDefaults(array_replace($matches, array('_route' => '_configurator_step')), array (  '_controller' => 'Sensio\\Bundle\\DistributionBundle\\Controller\\ConfiguratorController::stepAction',));
                }

                // _configurator_final
                if ($pathinfo === '/_configurator/final') {
                    return array (  '_controller' => 'Sensio\\Bundle\\DistributionBundle\\Controller\\ConfiguratorController::finalAction',  '_route' => '_configurator_final',);
                }

            }

        }

        if (0 === strpos($pathinfo, '/ticket')) {
            // hackzilla_ticket
            if (rtrim($pathinfo, '/') === '/ticket') {
                if (substr($pathinfo, -1) !== '/') {
                    return $this->redirect($pathinfo.'/', 'hackzilla_ticket');
                }

                return array (  '_controller' => 'Hackzilla\\Bundle\\TicketBundle\\Controller\\TicketController::indexAction',  '_route' => 'hackzilla_ticket',);
            }

            // hackzilla_ticket_show
            if (preg_match('#^/ticket/(?P<id>[^/]++)/show$#s', $pathinfo, $matches)) {
                return $this->mergeDefaults(array_replace($matches, array('_route' => 'hackzilla_ticket_show')), array (  '_controller' => 'Hackzilla\\Bundle\\TicketBundle\\Controller\\TicketController::showAction',));
            }

            // hackzilla_ticket_new
            if ($pathinfo === '/ticket/new') {
                return array (  '_controller' => 'Hackzilla\\Bundle\\TicketBundle\\Controller\\TicketController::newAction',  '_route' => 'hackzilla_ticket_new',);
            }

            // hackzilla_ticket_create
            if ($pathinfo === '/ticket/create') {
                if ($this->context->getMethod() != 'POST') {
                    $allow[] = 'POST';
                    goto not_hackzilla_ticket_create;
                }

                return array (  '_controller' => 'Hackzilla\\Bundle\\TicketBundle\\Controller\\TicketController::createAction',  '_route' => 'hackzilla_ticket_create',);
            }
            not_hackzilla_ticket_create:

            // hackzilla_ticket_delete
            if (preg_match('#^/ticket/(?P<id>[^/]++)/delete$#s', $pathinfo, $matches)) {
                if (!in_array($this->context->getMethod(), array('POST', 'DELETE'))) {
                    $allow = array_merge($allow, array('POST', 'DELETE'));
                    goto not_hackzilla_ticket_delete;
                }

                return $this->mergeDefaults(array_replace($matches, array('_route' => 'hackzilla_ticket_delete')), array (  '_controller' => 'Hackzilla\\Bundle\\TicketBundle\\Controller\\TicketController::deleteAction',));
            }
            not_hackzilla_ticket_delete:

            // hackzilla_ticket_reply
            if (preg_match('#^/ticket/(?P<id>[^/]++)/reply$#s', $pathinfo, $matches)) {
                return $this->mergeDefaults(array_replace($matches, array('_route' => 'hackzilla_ticket_reply')), array (  '_controller' => 'Hackzilla\\Bundle\\TicketBundle\\Controller\\TicketController::replyAction',));
            }

        }

        // homepage
        if (rtrim($pathinfo, '/') === '') {
            if (substr($pathinfo, -1) !== '/') {
                return $this->redirect($pathinfo.'/', 'homepage');
            }

            return array (  '_controller' => 'Intra\\UserBundle\\Controller\\HomeController::homeAction',  '_route' => 'homepage',);
        }

        if (0 === strpos($pathinfo, '/log')) {
            if (0 === strpos($pathinfo, '/login')) {
                // fos_user_security_login
                if ($pathinfo === '/login') {
                    return array (  '_controller' => 'FOS\\UserBundle\\Controller\\SecurityController::loginAction',  '_route' => 'fos_user_security_login',);
                }

                // fos_user_security_check
                if ($pathinfo === '/login_check') {
                    if ($this->context->getMethod() != 'POST') {
                        $allow[] = 'POST';
                        goto not_fos_user_security_check;
                    }

                    return array (  '_controller' => 'FOS\\UserBundle\\Controller\\SecurityController::checkAction',  '_route' => 'fos_user_security_check',);
                }
                not_fos_user_security_check:

            }

            // fos_user_security_logout
            if ($pathinfo === '/logout') {
                return array (  '_controller' => 'FOS\\UserBundle\\Controller\\SecurityController::logoutAction',  '_route' => 'fos_user_security_logout',);
            }

        }

        if (0 === strpos($pathinfo, '/profile')) {
            // fos_user_profile_show
            if (rtrim($pathinfo, '/') === '/profile') {
                if (!in_array($this->context->getMethod(), array('GET', 'HEAD'))) {
                    $allow = array_merge($allow, array('GET', 'HEAD'));
                    goto not_fos_user_profile_show;
                }

                if (substr($pathinfo, -1) !== '/') {
                    return $this->redirect($pathinfo.'/', 'fos_user_profile_show');
                }

                return array (  '_controller' => 'FOS\\UserBundle\\Controller\\ProfileController::showAction',  '_route' => 'fos_user_profile_show',);
            }
            not_fos_user_profile_show:

            // fos_user_profile_edit
            if ($pathinfo === '/profile/edit') {
                return array (  '_controller' => 'FOS\\UserBundle\\Controller\\ProfileController::editAction',  '_route' => 'fos_user_profile_edit',);
            }

        }

        if (0 === strpos($pathinfo, '/re')) {
            if (0 === strpos($pathinfo, '/register')) {
                // fos_user_registration_register
                if (rtrim($pathinfo, '/') === '/register') {
                    if (substr($pathinfo, -1) !== '/') {
                        return $this->redirect($pathinfo.'/', 'fos_user_registration_register');
                    }

                    return array (  '_controller' => 'FOS\\UserBundle\\Controller\\RegistrationController::registerAction',  '_route' => 'fos_user_registration_register',);
                }

                if (0 === strpos($pathinfo, '/register/c')) {
                    // fos_user_registration_check_email
                    if ($pathinfo === '/register/check-email') {
                        if (!in_array($this->context->getMethod(), array('GET', 'HEAD'))) {
                            $allow = array_merge($allow, array('GET', 'HEAD'));
                            goto not_fos_user_registration_check_email;
                        }

                        return array (  '_controller' => 'FOS\\UserBundle\\Controller\\RegistrationController::checkEmailAction',  '_route' => 'fos_user_registration_check_email',);
                    }
                    not_fos_user_registration_check_email:

                    if (0 === strpos($pathinfo, '/register/confirm')) {
                        // fos_user_registration_confirm
                        if (preg_match('#^/register/confirm/(?P<token>[^/]++)$#s', $pathinfo, $matches)) {
                            if (!in_array($this->context->getMethod(), array('GET', 'HEAD'))) {
                                $allow = array_merge($allow, array('GET', 'HEAD'));
                                goto not_fos_user_registration_confirm;
                            }

                            return $this->mergeDefaults(array_replace($matches, array('_route' => 'fos_user_registration_confirm')), array (  '_controller' => 'FOS\\UserBundle\\Controller\\RegistrationController::confirmAction',));
                        }
                        not_fos_user_registration_confirm:

                        // fos_user_registration_confirmed
                        if ($pathinfo === '/register/confirmed') {
                            if (!in_array($this->context->getMethod(), array('GET', 'HEAD'))) {
                                $allow = array_merge($allow, array('GET', 'HEAD'));
                                goto not_fos_user_registration_confirmed;
                            }

                            return array (  '_controller' => 'FOS\\UserBundle\\Controller\\RegistrationController::confirmedAction',  '_route' => 'fos_user_registration_confirmed',);
                        }
                        not_fos_user_registration_confirmed:

                    }

                }

            }

            if (0 === strpos($pathinfo, '/resetting')) {
                // fos_user_resetting_request
                if ($pathinfo === '/resetting/request') {
                    if (!in_array($this->context->getMethod(), array('GET', 'HEAD'))) {
                        $allow = array_merge($allow, array('GET', 'HEAD'));
                        goto not_fos_user_resetting_request;
                    }

                    return array (  '_controller' => 'FOS\\UserBundle\\Controller\\ResettingController::requestAction',  '_route' => 'fos_user_resetting_request',);
                }
                not_fos_user_resetting_request:

                // fos_user_resetting_send_email
                if ($pathinfo === '/resetting/send-email') {
                    if ($this->context->getMethod() != 'POST') {
                        $allow[] = 'POST';
                        goto not_fos_user_resetting_send_email;
                    }

                    return array (  '_controller' => 'FOS\\UserBundle\\Controller\\ResettingController::sendEmailAction',  '_route' => 'fos_user_resetting_send_email',);
                }
                not_fos_user_resetting_send_email:

                // fos_user_resetting_check_email
                if ($pathinfo === '/resetting/check-email') {
                    if (!in_array($this->context->getMethod(), array('GET', 'HEAD'))) {
                        $allow = array_merge($allow, array('GET', 'HEAD'));
                        goto not_fos_user_resetting_check_email;
                    }

                    return array (  '_controller' => 'FOS\\UserBundle\\Controller\\ResettingController::checkEmailAction',  '_route' => 'fos_user_resetting_check_email',);
                }
                not_fos_user_resetting_check_email:

                // fos_user_resetting_reset
                if (0 === strpos($pathinfo, '/resetting/reset') && preg_match('#^/resetting/reset/(?P<token>[^/]++)$#s', $pathinfo, $matches)) {
                    if (!in_array($this->context->getMethod(), array('GET', 'POST', 'HEAD'))) {
                        $allow = array_merge($allow, array('GET', 'POST', 'HEAD'));
                        goto not_fos_user_resetting_reset;
                    }

                    return $this->mergeDefaults(array_replace($matches, array('_route' => 'fos_user_resetting_reset')), array (  '_controller' => 'FOS\\UserBundle\\Controller\\ResettingController::resetAction',));
                }
                not_fos_user_resetting_reset:

            }

        }

        // fos_user_change_password
        if ($pathinfo === '/profile/change-password') {
            if (!in_array($this->context->getMethod(), array('GET', 'POST', 'HEAD'))) {
                $allow = array_merge($allow, array('GET', 'POST', 'HEAD'));
                goto not_fos_user_change_password;
            }

            return array (  '_controller' => 'FOS\\UserBundle\\Controller\\ChangePasswordController::changePasswordAction',  '_route' => 'fos_user_change_password',);
        }
        not_fos_user_change_password:

        if (0 === strpos($pathinfo, '/admin')) {
            // sonata_admin_redirect
            if (rtrim($pathinfo, '/') === '/admin') {
                if (substr($pathinfo, -1) !== '/') {
                    return $this->redirect($pathinfo.'/', 'sonata_admin_redirect');
                }

                return array (  '_controller' => 'Symfony\\Bundle\\FrameworkBundle\\Controller\\RedirectController::redirectAction',  'route' => 'sonata_admin_dashboard',  'permanent' => 'true',  '_route' => 'sonata_admin_redirect',);
            }

            // sonata_admin_dashboard
            if ($pathinfo === '/admin/dashboard') {
                return array (  '_controller' => 'Sonata\\AdminBundle\\Controller\\CoreController::dashboardAction',  '_route' => 'sonata_admin_dashboard',);
            }

            if (0 === strpos($pathinfo, '/admin/core')) {
                // sonata_admin_retrieve_form_element
                if ($pathinfo === '/admin/core/get-form-field-element') {
                    return array (  '_controller' => 'sonata.admin.controller.admin:retrieveFormFieldElementAction',  '_route' => 'sonata_admin_retrieve_form_element',);
                }

                // sonata_admin_append_form_element
                if ($pathinfo === '/admin/core/append-form-field-element') {
                    return array (  '_controller' => 'sonata.admin.controller.admin:appendFormFieldElementAction',  '_route' => 'sonata_admin_append_form_element',);
                }

                // sonata_admin_short_object_information
                if (0 === strpos($pathinfo, '/admin/core/get-short-object-description') && preg_match('#^/admin/core/get\\-short\\-object\\-description(?:\\.(?P<_format>html|json))?$#s', $pathinfo, $matches)) {
                    return $this->mergeDefaults(array_replace($matches, array('_route' => 'sonata_admin_short_object_information')), array (  '_controller' => 'sonata.admin.controller.admin:getShortObjectDescriptionAction',  '_format' => 'html',));
                }

                // sonata_admin_set_object_field_value
                if ($pathinfo === '/admin/core/set-object-field-value') {
                    return array (  '_controller' => 'sonata.admin.controller.admin:setObjectFieldValueAction',  '_route' => 'sonata_admin_set_object_field_value',);
                }

            }

            // sonata_admin_search
            if ($pathinfo === '/admin/search') {
                return array (  '_controller' => 'Sonata\\AdminBundle\\Controller\\CoreController::searchAction',  '_route' => 'sonata_admin_search',);
            }

            if (0 === strpos($pathinfo, '/admin/intra/user/user')) {
                // admin_intra_user_user_list
                if ($pathinfo === '/admin/intra/user/user/list') {
                    return array (  '_controller' => 'Intra\\UserBundle\\Controller\\UserAdminController::listAction',  '_sonata_admin' => 'intra_user.admin.user',  '_sonata_name' => 'admin_intra_user_user_list',  '_route' => 'admin_intra_user_user_list',);
                }

                // admin_intra_user_user_create
                if ($pathinfo === '/admin/intra/user/user/create') {
                    return array (  '_controller' => 'Intra\\UserBundle\\Controller\\UserAdminController::createAction',  '_sonata_admin' => 'intra_user.admin.user',  '_sonata_name' => 'admin_intra_user_user_create',  '_route' => 'admin_intra_user_user_create',);
                }

                // admin_intra_user_user_batch
                if ($pathinfo === '/admin/intra/user/user/batch') {
                    return array (  '_controller' => 'Intra\\UserBundle\\Controller\\UserAdminController::batchAction',  '_sonata_admin' => 'intra_user.admin.user',  '_sonata_name' => 'admin_intra_user_user_batch',  '_route' => 'admin_intra_user_user_batch',);
                }

                // admin_intra_user_user_edit
                if (preg_match('#^/admin/intra/user/user/(?P<id>[^/]++)/edit$#s', $pathinfo, $matches)) {
                    return $this->mergeDefaults(array_replace($matches, array('_route' => 'admin_intra_user_user_edit')), array (  '_controller' => 'Intra\\UserBundle\\Controller\\UserAdminController::editAction',  '_sonata_admin' => 'intra_user.admin.user',  '_sonata_name' => 'admin_intra_user_user_edit',));
                }

                // admin_intra_user_user_delete
                if (preg_match('#^/admin/intra/user/user/(?P<id>[^/]++)/delete$#s', $pathinfo, $matches)) {
                    return $this->mergeDefaults(array_replace($matches, array('_route' => 'admin_intra_user_user_delete')), array (  '_controller' => 'Intra\\UserBundle\\Controller\\UserAdminController::deleteAction',  '_sonata_admin' => 'intra_user.admin.user',  '_sonata_name' => 'admin_intra_user_user_delete',));
                }

                // admin_intra_user_user_show
                if (preg_match('#^/admin/intra/user/user/(?P<id>[^/]++)/show$#s', $pathinfo, $matches)) {
                    return $this->mergeDefaults(array_replace($matches, array('_route' => 'admin_intra_user_user_show')), array (  '_controller' => 'Intra\\UserBundle\\Controller\\UserAdminController::showAction',  '_sonata_admin' => 'intra_user.admin.user',  '_sonata_name' => 'admin_intra_user_user_show',));
                }

                // admin_intra_user_user_export
                if ($pathinfo === '/admin/intra/user/user/export') {
                    return array (  '_controller' => 'Intra\\UserBundle\\Controller\\UserAdminController::exportAction',  '_sonata_admin' => 'intra_user.admin.user',  '_sonata_name' => 'admin_intra_user_user_export',  '_route' => 'admin_intra_user_user_export',);
                }

            }

        }

        // ccdn_forum_admin_index
        if (preg_match('#^/(?P<_locale>[^/]++)/forum/admin/?$#s', $pathinfo, $matches)) {
            if (substr($pathinfo, -1) !== '/') {
                return $this->redirect($pathinfo.'/', 'ccdn_forum_admin_index');
            }

            return $this->mergeDefaults(array_replace($matches, array('_route' => 'ccdn_forum_admin_index')), array (  '_controller' => 'CCDNForum\\ForumBundle\\Controller\\AdminPanelController::IndexAction',  '_locale' => 'en',));
        }

        // ccdn_forum_admin_forum_list
        if (preg_match('#^/(?P<_locale>[^/]++)/forum/admin/manage\\-forums/?$#s', $pathinfo, $matches)) {
            if (substr($pathinfo, -1) !== '/') {
                return $this->redirect($pathinfo.'/', 'ccdn_forum_admin_forum_list');
            }

            return $this->mergeDefaults(array_replace($matches, array('_route' => 'ccdn_forum_admin_forum_list')), array (  '_controller' => 'CCDNForum\\ForumBundle\\Controller\\AdminForumController::listAction',  '_locale' => 'en',));
        }

        // ccdn_forum_admin_forum_create
        if (preg_match('#^/(?P<_locale>[^/]++)/forum/admin/manage\\-forums/create$#s', $pathinfo, $matches)) {
            return $this->mergeDefaults(array_replace($matches, array('_route' => 'ccdn_forum_admin_forum_create')), array (  '_controller' => 'CCDNForum\\ForumBundle\\Controller\\AdminForumController::createAction',  '_locale' => 'en',));
        }

        // ccdn_forum_admin_forum_create_process
        if (preg_match('#^/(?P<_locale>[^/]++)/forum/admin/manage\\-forums/create/process$#s', $pathinfo, $matches)) {
            return $this->mergeDefaults(array_replace($matches, array('_route' => 'ccdn_forum_admin_forum_create_process')), array (  '_controller' => 'CCDNForum\\ForumBundle\\Controller\\AdminForumController::createProcessAction',  '_locale' => 'en',));
        }

        // ccdn_forum_admin_forum_edit
        if (preg_match('#^/(?P<_locale>[^/]++)/forum/admin/manage\\-forums/edit/(?P<forumId>[^/]++)$#s', $pathinfo, $matches)) {
            return $this->mergeDefaults(array_replace($matches, array('_route' => 'ccdn_forum_admin_forum_edit')), array (  '_controller' => 'CCDNForum\\ForumBundle\\Controller\\AdminForumController::editAction',  '_locale' => 'en',));
        }

        // ccdn_forum_admin_forum_edit_process
        if (preg_match('#^/(?P<_locale>[^/]++)/forum/admin/manage\\-forums/edit/(?P<forumId>[^/]++)/process$#s', $pathinfo, $matches)) {
            return $this->mergeDefaults(array_replace($matches, array('_route' => 'ccdn_forum_admin_forum_edit_process')), array (  '_controller' => 'CCDNForum\\ForumBundle\\Controller\\AdminForumController::editProcessAction',  '_locale' => 'en',));
        }

        // ccdn_forum_admin_forum_delete
        if (preg_match('#^/(?P<_locale>[^/]++)/forum/admin/manage\\-forums/delete/(?P<forumId>[^/]++)$#s', $pathinfo, $matches)) {
            return $this->mergeDefaults(array_replace($matches, array('_route' => 'ccdn_forum_admin_forum_delete')), array (  '_controller' => 'CCDNForum\\ForumBundle\\Controller\\AdminForumController::deleteAction',  '_locale' => 'en',));
        }

        // ccdn_forum_admin_forum_delete_process
        if (preg_match('#^/(?P<_locale>[^/]++)/forum/admin/manage\\-forums/delete/(?P<forumId>[^/]++)/process$#s', $pathinfo, $matches)) {
            return $this->mergeDefaults(array_replace($matches, array('_route' => 'ccdn_forum_admin_forum_delete_process')), array (  '_controller' => 'CCDNForum\\ForumBundle\\Controller\\AdminForumController::deleteProcessAction',  '_locale' => 'en',));
        }

        // ccdn_forum_admin_category_list
        if (preg_match('#^/(?P<_locale>[^/]++)/forum/admin/manage\\-categories/?$#s', $pathinfo, $matches)) {
            if (substr($pathinfo, -1) !== '/') {
                return $this->redirect($pathinfo.'/', 'ccdn_forum_admin_category_list');
            }

            return $this->mergeDefaults(array_replace($matches, array('_route' => 'ccdn_forum_admin_category_list')), array (  '_controller' => 'CCDNForum\\ForumBundle\\Controller\\AdminCategoryController::listAction',  '_locale' => 'en',));
        }

        // ccdn_forum_admin_category_create
        if (preg_match('#^/(?P<_locale>[^/]++)/forum/admin/manage\\-categories/create$#s', $pathinfo, $matches)) {
            return $this->mergeDefaults(array_replace($matches, array('_route' => 'ccdn_forum_admin_category_create')), array (  '_controller' => 'CCDNForum\\ForumBundle\\Controller\\AdminCategoryController::createAction',  '_locale' => 'en',));
        }

        // ccdn_forum_admin_category_create_process
        if (preg_match('#^/(?P<_locale>[^/]++)/forum/admin/manage\\-categories/create/process$#s', $pathinfo, $matches)) {
            return $this->mergeDefaults(array_replace($matches, array('_route' => 'ccdn_forum_admin_category_create_process')), array (  '_controller' => 'CCDNForum\\ForumBundle\\Controller\\AdminCategoryController::createProcessAction',  '_locale' => 'en',));
        }

        // ccdn_forum_admin_category_edit
        if (preg_match('#^/(?P<_locale>[^/]++)/forum/admin/manage\\-categories/edit/(?P<categoryId>[^/]++)$#s', $pathinfo, $matches)) {
            return $this->mergeDefaults(array_replace($matches, array('_route' => 'ccdn_forum_admin_category_edit')), array (  '_controller' => 'CCDNForum\\ForumBundle\\Controller\\AdminCategoryController::editAction',  '_locale' => 'en',));
        }

        // ccdn_forum_admin_category_edit_process
        if (preg_match('#^/(?P<_locale>[^/]++)/forum/admin/manage\\-categories/edit/(?P<categoryId>[^/]++)/process$#s', $pathinfo, $matches)) {
            return $this->mergeDefaults(array_replace($matches, array('_route' => 'ccdn_forum_admin_category_edit_process')), array (  '_controller' => 'CCDNForum\\ForumBundle\\Controller\\AdminCategoryController::editProcessAction',  '_locale' => 'en',));
        }

        // ccdn_forum_admin_category_delete
        if (preg_match('#^/(?P<_locale>[^/]++)/forum/admin/manage\\-categories/delete/(?P<categoryId>[^/]++)$#s', $pathinfo, $matches)) {
            return $this->mergeDefaults(array_replace($matches, array('_route' => 'ccdn_forum_admin_category_delete')), array (  '_controller' => 'CCDNForum\\ForumBundle\\Controller\\AdminCategoryController::deleteAction',  '_locale' => 'en',));
        }

        // ccdn_forum_admin_category_delete_process
        if (preg_match('#^/(?P<_locale>[^/]++)/forum/admin/manage\\-categories/delete/(?P<categoryId>[^/]++)/process$#s', $pathinfo, $matches)) {
            return $this->mergeDefaults(array_replace($matches, array('_route' => 'ccdn_forum_admin_category_delete_process')), array (  '_controller' => 'CCDNForum\\ForumBundle\\Controller\\AdminCategoryController::deleteProcessAction',  '_locale' => 'en',));
        }

        // ccdn_forum_admin_category_reorder_up
        if (preg_match('#^/(?P<_locale>[^/]++)/forum/admin/manage\\-categories/reorder/(?P<categoryId>[^/]++)/up$#s', $pathinfo, $matches)) {
            return $this->mergeDefaults(array_replace($matches, array('_route' => 'ccdn_forum_admin_category_reorder_up')), array (  '_controller' => 'CCDNForum\\ForumBundle\\Controller\\AdminCategoryController::reorderAction',  '_locale' => 'en',  'direction' => 0,));
        }

        // ccdn_forum_admin_category_reorder_down
        if (preg_match('#^/(?P<_locale>[^/]++)/forum/admin/manage\\-categories/reorder/(?P<categoryId>[^/]++)/down$#s', $pathinfo, $matches)) {
            return $this->mergeDefaults(array_replace($matches, array('_route' => 'ccdn_forum_admin_category_reorder_down')), array (  '_controller' => 'CCDNForum\\ForumBundle\\Controller\\AdminCategoryController::reorderAction',  '_locale' => 'en',  'direction' => 1,));
        }

        // ccdn_forum_admin_board_list
        if (preg_match('#^/(?P<_locale>[^/]++)/forum/admin/manage\\-boards/?$#s', $pathinfo, $matches)) {
            if (substr($pathinfo, -1) !== '/') {
                return $this->redirect($pathinfo.'/', 'ccdn_forum_admin_board_list');
            }

            return $this->mergeDefaults(array_replace($matches, array('_route' => 'ccdn_forum_admin_board_list')), array (  '_controller' => 'CCDNForum\\ForumBundle\\Controller\\AdminBoardController::listAction',  '_locale' => 'en',));
        }

        // ccdn_forum_admin_board_create
        if (preg_match('#^/(?P<_locale>[^/]++)/forum/admin/manage\\-boards/create$#s', $pathinfo, $matches)) {
            return $this->mergeDefaults(array_replace($matches, array('_route' => 'ccdn_forum_admin_board_create')), array (  '_controller' => 'CCDNForum\\ForumBundle\\Controller\\AdminBoardController::createAction',  '_locale' => 'en',));
        }

        // ccdn_forum_admin_board_create_process
        if (preg_match('#^/(?P<_locale>[^/]++)/forum/admin/manage\\-boards/create/process$#s', $pathinfo, $matches)) {
            return $this->mergeDefaults(array_replace($matches, array('_route' => 'ccdn_forum_admin_board_create_process')), array (  '_controller' => 'CCDNForum\\ForumBundle\\Controller\\AdminBoardController::createProcessAction',  '_locale' => 'en',));
        }

        // ccdn_forum_admin_board_edit
        if (preg_match('#^/(?P<_locale>[^/]++)/forum/admin/manage\\-boards/edit/(?P<boardId>[^/]++)$#s', $pathinfo, $matches)) {
            return $this->mergeDefaults(array_replace($matches, array('_route' => 'ccdn_forum_admin_board_edit')), array (  '_controller' => 'CCDNForum\\ForumBundle\\Controller\\AdminBoardController::editAction',  '_locale' => 'en',));
        }

        // ccdn_forum_admin_board_edit_process
        if (preg_match('#^/(?P<_locale>[^/]++)/forum/admin/manage\\-boards/edit/(?P<boardId>[^/]++)/process$#s', $pathinfo, $matches)) {
            return $this->mergeDefaults(array_replace($matches, array('_route' => 'ccdn_forum_admin_board_edit_process')), array (  '_controller' => 'CCDNForum\\ForumBundle\\Controller\\AdminBoardController::editProcessAction',  '_locale' => 'en',));
        }

        // ccdn_forum_admin_board_delete
        if (preg_match('#^/(?P<_locale>[^/]++)/forum/admin/manage\\-boards/delete/(?P<boardId>[^/]++)$#s', $pathinfo, $matches)) {
            return $this->mergeDefaults(array_replace($matches, array('_route' => 'ccdn_forum_admin_board_delete')), array (  '_controller' => 'CCDNForum\\ForumBundle\\Controller\\AdminBoardController::deleteAction',  '_locale' => 'en',));
        }

        // ccdn_forum_admin_board_delete_process
        if (preg_match('#^/(?P<_locale>[^/]++)/forum/admin/manage\\-boards/delete/(?P<boardId>[^/]++)/process$#s', $pathinfo, $matches)) {
            return $this->mergeDefaults(array_replace($matches, array('_route' => 'ccdn_forum_admin_board_delete_process')), array (  '_controller' => 'CCDNForum\\ForumBundle\\Controller\\AdminBoardController::deleteProcessAction',  '_locale' => 'en',));
        }

        // ccdn_forum_admin_board_reorder_up
        if (preg_match('#^/(?P<_locale>[^/]++)/forum/admin/manage\\-boards/reorder/(?P<boardId>[^/]++)/up$#s', $pathinfo, $matches)) {
            return $this->mergeDefaults(array_replace($matches, array('_route' => 'ccdn_forum_admin_board_reorder_up')), array (  '_controller' => 'CCDNForum\\ForumBundle\\Controller\\AdminBoardController::reorderAction',  '_locale' => 'en',  'direction' => 0,));
        }

        // ccdn_forum_admin_board_reorder_down
        if (preg_match('#^/(?P<_locale>[^/]++)/forum/admin/manage\\-boards/reorder/(?P<boardId>[^/]++)/down$#s', $pathinfo, $matches)) {
            return $this->mergeDefaults(array_replace($matches, array('_route' => 'ccdn_forum_admin_board_reorder_down')), array (  '_controller' => 'CCDNForum\\ForumBundle\\Controller\\AdminBoardController::reorderAction',  '_locale' => 'en',  'direction' => 1,));
        }

        // ccdn_forum_moderator_topic_close
        if (preg_match('#^/(?P<_locale>[^/]++)/forum/(?P<forumName>[^/]++)/moderator/manage\\-topics/(?P<topicId>[^/]++)/close$#s', $pathinfo, $matches)) {
            return $this->mergeDefaults(array_replace($matches, array('_route' => 'ccdn_forum_moderator_topic_close')), array (  '_controller' => 'CCDNForum\\ForumBundle\\Controller\\ModeratorTopicController::closeAction',  '_locale' => 'en',  'forumName' => 'default',));
        }

        // ccdn_forum_moderator_topic_reopen
        if (preg_match('#^/(?P<_locale>[^/]++)/forum/(?P<forumName>[^/]++)/moderator/manage\\-topics/(?P<topicId>[^/]++)/reopen$#s', $pathinfo, $matches)) {
            return $this->mergeDefaults(array_replace($matches, array('_route' => 'ccdn_forum_moderator_topic_reopen')), array (  '_controller' => 'CCDNForum\\ForumBundle\\Controller\\ModeratorTopicController::reopenAction',  '_locale' => 'en',  'forumName' => 'default',));
        }

        // ccdn_forum_moderator_topic_sticky
        if (preg_match('#^/(?P<_locale>[^/]++)/forum/(?P<forumName>[^/]++)/moderator/manage\\-topics/(?P<topicId>[^/]++)/sticky$#s', $pathinfo, $matches)) {
            return $this->mergeDefaults(array_replace($matches, array('_route' => 'ccdn_forum_moderator_topic_sticky')), array (  '_controller' => 'CCDNForum\\ForumBundle\\Controller\\ModeratorTopicController::stickyAction',  '_locale' => 'en',  'forumName' => 'default',));
        }

        // ccdn_forum_moderator_topic_unsticky
        if (preg_match('#^/(?P<_locale>[^/]++)/forum/(?P<forumName>[^/]++)/moderator/manage\\-topics/(?P<topicId>[^/]++)/unsticky$#s', $pathinfo, $matches)) {
            return $this->mergeDefaults(array_replace($matches, array('_route' => 'ccdn_forum_moderator_topic_unsticky')), array (  '_controller' => 'CCDNForum\\ForumBundle\\Controller\\ModeratorTopicController::unstickyAction',  '_locale' => 'en',  'forumName' => 'default',));
        }

        // ccdn_forum_moderator_topic_delete
        if (preg_match('#^/(?P<_locale>[^/]++)/forum/(?P<forumName>[^/]++)/moderator/manage\\-topics/(?P<topicId>[^/]++)/delete$#s', $pathinfo, $matches)) {
            return $this->mergeDefaults(array_replace($matches, array('_route' => 'ccdn_forum_moderator_topic_delete')), array (  '_controller' => 'CCDNForum\\ForumBundle\\Controller\\ModeratorTopicController::deleteAction',  '_locale' => 'en',  'forumName' => 'default',));
        }

        // ccdn_forum_moderator_topic_delete_process
        if (preg_match('#^/(?P<_locale>[^/]++)/forum/(?P<forumName>[^/]++)/moderator/manage\\-topics/(?P<topicId>[^/]++)/delete/process$#s', $pathinfo, $matches)) {
            return $this->mergeDefaults(array_replace($matches, array('_route' => 'ccdn_forum_moderator_topic_delete_process')), array (  '_controller' => 'CCDNForum\\ForumBundle\\Controller\\ModeratorTopicController::deleteProcessAction',  '_locale' => 'en',  'forumName' => 'default',));
        }

        // ccdn_forum_moderator_topic_restore
        if (preg_match('#^/(?P<_locale>[^/]++)/forum/(?P<forumName>[^/]++)/moderator/manage\\-topics/(?P<topicId>[^/]++)/restore$#s', $pathinfo, $matches)) {
            return $this->mergeDefaults(array_replace($matches, array('_route' => 'ccdn_forum_moderator_topic_restore')), array (  '_controller' => 'CCDNForum\\ForumBundle\\Controller\\ModeratorTopicController::restoreAction',  '_locale' => 'en',  'forumName' => 'default',));
        }

        // ccdn_forum_moderator_topic_change_board
        if (preg_match('#^/(?P<_locale>[^/]++)/forum/(?P<forumName>[^/]++)/moderator/manage\\-topics/(?P<topicId>[^/]++)/change\\-board$#s', $pathinfo, $matches)) {
            return $this->mergeDefaults(array_replace($matches, array('_route' => 'ccdn_forum_moderator_topic_change_board')), array (  '_controller' => 'CCDNForum\\ForumBundle\\Controller\\ModeratorTopicController::changeBoardAction',  '_locale' => 'en',  'forumName' => 'default',));
        }

        // ccdn_forum_moderator_topic_change_board_process
        if (preg_match('#^/(?P<_locale>[^/]++)/forum/(?P<forumName>[^/]++)/moderator/manage\\-topics/(?P<topicId>[^/]++)/change\\-board/process$#s', $pathinfo, $matches)) {
            return $this->mergeDefaults(array_replace($matches, array('_route' => 'ccdn_forum_moderator_topic_change_board_process')), array (  '_controller' => 'CCDNForum\\ForumBundle\\Controller\\ModeratorTopicController::changeBoardProcessAction',  '_locale' => 'en',  'forumName' => 'default',));
        }

        // ccdn_forum_moderator_post_lock
        if (preg_match('#^/(?P<_locale>[^/]++)/forum/(?P<forumName>[^/]++)/moderator/manage\\-posts/(?P<postId>[^/]++)/lock$#s', $pathinfo, $matches)) {
            return $this->mergeDefaults(array_replace($matches, array('_route' => 'ccdn_forum_moderator_post_lock')), array (  '_controller' => 'CCDNForum\\ForumBundle\\Controller\\ModeratorPostController::lockAction',  '_locale' => 'en',));
        }

        // ccdn_forum_moderator_post_unlock
        if (preg_match('#^/(?P<_locale>[^/]++)/forum/(?P<forumName>[^/]++)/moderator/manage\\-posts/(?P<postId>[^/]++)/unlock$#s', $pathinfo, $matches)) {
            return $this->mergeDefaults(array_replace($matches, array('_route' => 'ccdn_forum_moderator_post_unlock')), array (  '_controller' => 'CCDNForum\\ForumBundle\\Controller\\ModeratorPostController::unlockAction',  '_locale' => 'en',));
        }

        // ccdn_forum_moderator_post_unlock_process
        if (preg_match('#^/(?P<_locale>[^/]++)/forum/(?P<forumName>[^/]++)/moderator/manage\\-posts/(?P<postId>[^/]++)/unlock/process$#s', $pathinfo, $matches)) {
            return $this->mergeDefaults(array_replace($matches, array('_route' => 'ccdn_forum_moderator_post_unlock_process')), array (  '_controller' => 'CCDNForum\\ForumBundle\\Controller\\ModeratorPostController::unlockProcessAction',  '_locale' => 'en',));
        }

        // ccdn_forum_moderator_post_restore
        if (preg_match('#^/(?P<_locale>[^/]++)/forum/(?P<forumName>[^/]++)/moderator/manage\\-posts/(?P<postId>[^/]++)/restore$#s', $pathinfo, $matches)) {
            return $this->mergeDefaults(array_replace($matches, array('_route' => 'ccdn_forum_moderator_post_restore')), array (  '_controller' => 'CCDNForum\\ForumBundle\\Controller\\ModeratorPostController::restoreAction',  '_locale' => 'en',));
        }

        // ccdn_forum_user_category_index
        if (preg_match('#^/(?P<_locale>[^/]++)/forum(?:/(?P<forumName>[^/]++))?$#s', $pathinfo, $matches)) {
            return $this->mergeDefaults(array_replace($matches, array('_route' => 'ccdn_forum_user_category_index')), array (  '_controller' => 'CCDNForum\\ForumBundle\\Controller\\UserCategoryController::indexAction',  '_locale' => 'en',  'forumName' => 'default',));
        }

        // ccdn_forum_user_category_show
        if (preg_match('#^/(?P<_locale>[^/]++)/forum/(?P<forumName>[^/]++)/category/(?P<categoryId>[^/]++)$#s', $pathinfo, $matches)) {
            return $this->mergeDefaults(array_replace($matches, array('_route' => 'ccdn_forum_user_category_show')), array (  '_controller' => 'CCDNForum\\ForumBundle\\Controller\\UserCategoryController::showAction',  '_locale' => 'en',  'forumName' => 'default',));
        }

        // ccdn_forum_user_board_show
        if (preg_match('#^/(?P<_locale>[^/]++)/forum/(?P<forumName>[^/]++)/board/(?P<boardId>[^/]++)$#s', $pathinfo, $matches)) {
            return $this->mergeDefaults(array_replace($matches, array('_route' => 'ccdn_forum_user_board_show')), array (  '_controller' => 'CCDNForum\\ForumBundle\\Controller\\UserBoardController::showAction',  '_locale' => 'en',  'forumName' => 'default',));
        }

        // ccdn_forum_user_topic_show
        if (preg_match('#^/(?P<_locale>[^/]++)/forum/(?P<forumName>[^/]++)/topic/(?P<topicId>[^/]++)$#s', $pathinfo, $matches)) {
            return $this->mergeDefaults(array_replace($matches, array('_route' => 'ccdn_forum_user_topic_show')), array (  '_controller' => 'CCDNForum\\ForumBundle\\Controller\\UserTopicController::showAction',  '_locale' => 'en',  'forumName' => 'default',));
        }

        // ccdn_forum_user_topic_create
        if (preg_match('#^/(?P<_locale>[^/]++)/forum/(?P<forumName>[^/]++)/topic/create/for\\-board/(?P<boardId>[^/]++)$#s', $pathinfo, $matches)) {
            return $this->mergeDefaults(array_replace($matches, array('_route' => 'ccdn_forum_user_topic_create')), array (  '_controller' => 'CCDNForum\\ForumBundle\\Controller\\UserTopicController::createAction',  '_locale' => 'en',  'forumName' => 'default',));
        }

        // ccdn_forum_user_topic_create_process
        if (preg_match('#^/(?P<_locale>[^/]++)/forum/(?P<forumName>[^/]++)/topic/create/for\\-board/(?P<boardId>[^/]++)/process$#s', $pathinfo, $matches)) {
            return $this->mergeDefaults(array_replace($matches, array('_route' => 'ccdn_forum_user_topic_create_process')), array (  '_controller' => 'CCDNForum\\ForumBundle\\Controller\\UserTopicController::createProcessAction',  '_locale' => 'en',  'forumName' => 'default',));
        }

        // ccdn_forum_user_topic_reply
        if (preg_match('#^/(?P<_locale>[^/]++)/forum/(?P<forumName>[^/]++)/topic/(?P<topicId>[^/]++)/reply$#s', $pathinfo, $matches)) {
            return $this->mergeDefaults(array_replace($matches, array('_route' => 'ccdn_forum_user_topic_reply')), array (  '_controller' => 'CCDNForum\\ForumBundle\\Controller\\UserTopicController::replyAction',  '_locale' => 'en',  'forumName' => 'default',));
        }

        // ccdn_forum_user_topic_reply_process
        if (preg_match('#^/(?P<_locale>[^/]++)/forum/(?P<forumName>[^/]++)/topic/(?P<topicId>[^/]++)/reply/process$#s', $pathinfo, $matches)) {
            return $this->mergeDefaults(array_replace($matches, array('_route' => 'ccdn_forum_user_topic_reply_process')), array (  '_controller' => 'CCDNForum\\ForumBundle\\Controller\\UserTopicController::replyProcessAction',  '_locale' => 'en',  'forumName' => 'default',));
        }

        // ccdn_forum_user_post_show
        if (preg_match('#^/(?P<_locale>[^/]++)/forum/(?P<forumName>[^/]++)/post/(?P<postId>[^/]++)$#s', $pathinfo, $matches)) {
            return $this->mergeDefaults(array_replace($matches, array('_route' => 'ccdn_forum_user_post_show')), array (  '_controller' => 'CCDNForum\\ForumBundle\\Controller\\UserPostController::showAction',  '_locale' => 'en',  'forumName' => 'default',));
        }

        // ccdn_forum_user_post_edit
        if (preg_match('#^/(?P<_locale>[^/]++)/forum/(?P<forumName>[^/]++)/post/(?P<postId>[^/]++)/edit$#s', $pathinfo, $matches)) {
            return $this->mergeDefaults(array_replace($matches, array('_route' => 'ccdn_forum_user_post_edit')), array (  '_controller' => 'CCDNForum\\ForumBundle\\Controller\\UserPostController::editAction',  '_locale' => 'en',  'forumName' => 'default',));
        }

        // ccdn_forum_user_post_edit_process
        if (preg_match('#^/(?P<_locale>[^/]++)/forum/(?P<forumName>[^/]++)/post/(?P<postId>[^/]++)/edit/process$#s', $pathinfo, $matches)) {
            return $this->mergeDefaults(array_replace($matches, array('_route' => 'ccdn_forum_user_post_edit_process')), array (  '_controller' => 'CCDNForum\\ForumBundle\\Controller\\UserPostController::editProcessAction',  '_locale' => 'en',  'forumName' => 'default',));
        }

        // ccdn_forum_user_post_delete
        if (preg_match('#^/(?P<_locale>[^/]++)/forum/(?P<forumName>[^/]++)/post/(?P<postId>[^/]++)/delete$#s', $pathinfo, $matches)) {
            return $this->mergeDefaults(array_replace($matches, array('_route' => 'ccdn_forum_user_post_delete')), array (  '_controller' => 'CCDNForum\\ForumBundle\\Controller\\UserPostController::deleteAction',  '_locale' => 'en',  'forumName' => 'default',));
        }

        // ccdn_forum_user_post_delete_process
        if (preg_match('#^/(?P<_locale>[^/]++)/forum/(?P<forumName>[^/]++)/post/(?P<postId>[^/]++)/delete/process$#s', $pathinfo, $matches)) {
            return $this->mergeDefaults(array_replace($matches, array('_route' => 'ccdn_forum_user_post_delete_process')), array (  '_controller' => 'CCDNForum\\ForumBundle\\Controller\\UserPostController::deleteProcessAction',  '_locale' => 'en',  'forumName' => 'default',));
        }

        // ccdn_forum_user_subscription_index
        if (preg_match('#^/(?P<_locale>[^/]++)/forum/(?P<forumName>[^/]++)/subscription/?$#s', $pathinfo, $matches)) {
            if (substr($pathinfo, -1) !== '/') {
                return $this->redirect($pathinfo.'/', 'ccdn_forum_user_subscription_index');
            }

            return $this->mergeDefaults(array_replace($matches, array('_route' => 'ccdn_forum_user_subscription_index')), array (  '_controller' => 'CCDNForum\\ForumBundle\\Controller\\UserSubscriptionController::indexAction',  '_locale' => 'en',));
        }

        // ccdn_forum_user_subscription_subscribe
        if (preg_match('#^/(?P<_locale>[^/]++)/forum/(?P<forumName>[^/]++)/subscription/topic/(?P<topicId>[^/]++)/subscribe$#s', $pathinfo, $matches)) {
            return $this->mergeDefaults(array_replace($matches, array('_route' => 'ccdn_forum_user_subscription_subscribe')), array (  '_controller' => 'CCDNForum\\ForumBundle\\Controller\\UserSubscriptionController::subscribeAction',  '_locale' => 'en',));
        }

        // ccdn_forum_user_subscription_unsubscribe
        if (preg_match('#^/(?P<_locale>[^/]++)/forum/(?P<forumName>[^/]++)/subscription/topic/(?P<topicId>[^/]++)/unsubscribe$#s', $pathinfo, $matches)) {
            return $this->mergeDefaults(array_replace($matches, array('_route' => 'ccdn_forum_user_subscription_unsubscribe')), array (  '_controller' => 'CCDNForum\\ForumBundle\\Controller\\UserSubscriptionController::unsubscribeAction',  '_locale' => 'en',));
        }

        // ccdn_homepage
        if ($pathinfo === '/forum') {
            return array (  '_controller' => 'CCDNForum\\ForumBundle\\Controller\\UserCategoryController::indexAction',  '_locale' => 'en',  'forumName' => 'default',  '_route' => 'ccdn_homepage',);
        }

        throw 0 < count($allow) ? new MethodNotAllowedException(array_unique($allow)) : new ResourceNotFoundException();
    }
}
