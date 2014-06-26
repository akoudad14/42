<?php

/* CCDNForumForumBundle:User/Subscription:show.html.twig */
class __TwigTemplate_f0bf19a1639b3e8ae529425d54f7702fc449a952a64c47505a36890f5d994c94 extends Twig_Template
{
    public function __construct(Twig_Environment $env)
    {
        parent::__construct($env);

        $this->parent = $this->env->loadTemplate("CCDNForumForumBundle:Common:Layout/base.html.twig");

        $this->blocks = array(
            'title' => array($this, 'block_title'),
            'sidebar' => array($this, 'block_sidebar'),
            'body_content' => array($this, 'block_body_content'),
        );
    }

    protected function doGetParent(array $context)
    {
        return "CCDNForumForumBundle:Common:Layout/base.html.twig";
    }

    protected function doDisplay(array $context, array $blocks = array())
    {
        // line 3
        $context["LayoutTemplate"] = $this->getAttribute($this->getAttribute($this->getAttribute((isset($context["ccdn_forum_forum"]) ? $context["ccdn_forum_forum"] : $this->getContext($context, "ccdn_forum_forum")), "subscription"), "list"), "layout_template");
        $this->parent->display($context, array_merge($this->blocks, $blocks));
    }

    // line 5
    public function block_title($context, array $blocks = array())
    {
        // line 6
        echo twig_escape_filter($this->env, $this->env->getExtension('translator')->trans("title.subscription.index", array(), "CCDNForumForumBundle"), "html", null, true);
    }

    // line 9
    public function block_sidebar($context, array $blocks = array())
    {
        // line 10
        ob_start();
        // line 11
        $this->displayParentBlock("sidebar", $context, $blocks);
        // line 12
        $this->env->loadTemplate("CCDNForumForumBundle:Common:Layout/Sidebar/user_subscriptions.html.twig")->display($context);
        echo trim(preg_replace('/>\s+</', '><', ob_get_clean()));
    }

    // line 47
    public function block_body_content($context, array $blocks = array())
    {
        // line 48
        ob_start();
        // line 50
        echo "<section class=\"row clearfix\">
\t\t<div class=\"col-md-12\">
\t\t\t<ul class=\"nav nav-tabs\">";
        // line 53
        $context["tabs"] = $this;
        // line 54
        if ((!(null === (isset($context["forum"]) ? $context["forum"] : $this->getContext($context, "forum"))))) {
            // line 55
            echo $context["tabs"]->getsubscription_tab("all", (isset($context["forumName"]) ? $context["forumName"] : $this->getContext($context, "forumName")), "all", (isset($context["filter"]) ? $context["filter"] : $this->getContext($context, "filter")), $this->getAttribute((isset($context["total_subscribed_forums"]) ? $context["total_subscribed_forums"] : $this->getContext($context, "total_subscribed_forums")), "count_read", array(), "array"), $this->getAttribute((isset($context["total_subscribed_forums"]) ? $context["total_subscribed_forums"] : $this->getContext($context, "total_subscribed_forums")), "count_unread", array(), "array"), $this->getAttribute((isset($context["total_subscribed_forums"]) ? $context["total_subscribed_forums"] : $this->getContext($context, "total_subscribed_forums")), "count_total", array(), "array"));
            // line 56
            echo $context["tabs"]->getsubscription_tab("unread", (isset($context["forumName"]) ? $context["forumName"] : $this->getContext($context, "forumName")), "unread", (isset($context["filter"]) ? $context["filter"] : $this->getContext($context, "filter")), null, $this->getAttribute((isset($context["total_subscribed_forums"]) ? $context["total_subscribed_forums"] : $this->getContext($context, "total_subscribed_forums")), "count_unread", array(), "array"), null);
            // line 57
            echo $context["tabs"]->getsubscription_tab("read", (isset($context["forumName"]) ? $context["forumName"] : $this->getContext($context, "forumName")), "read", (isset($context["filter"]) ? $context["filter"] : $this->getContext($context, "filter")), $this->getAttribute((isset($context["total_subscribed_forums"]) ? $context["total_subscribed_forums"] : $this->getContext($context, "total_subscribed_forums")), "count_read", array(), "array"), null, null);
        } else {
            // line 59
            echo $context["tabs"]->getsubscription_tab("all", "~", "all", (isset($context["filter"]) ? $context["filter"] : $this->getContext($context, "filter")), $this->getAttribute((isset($context["total_subscribed_forums"]) ? $context["total_subscribed_forums"] : $this->getContext($context, "total_subscribed_forums")), "count_read", array(), "array"), $this->getAttribute((isset($context["total_subscribed_forums"]) ? $context["total_subscribed_forums"] : $this->getContext($context, "total_subscribed_forums")), "count_unread", array(), "array"), $this->getAttribute((isset($context["total_subscribed_forums"]) ? $context["total_subscribed_forums"] : $this->getContext($context, "total_subscribed_forums")), "count_total", array(), "array"));
            // line 60
            echo $context["tabs"]->getsubscription_tab("unread", "~", "unread", (isset($context["filter"]) ? $context["filter"] : $this->getContext($context, "filter")), null, $this->getAttribute((isset($context["total_subscribed_forums"]) ? $context["total_subscribed_forums"] : $this->getContext($context, "total_subscribed_forums")), "count_unread", array(), "array"), null);
            // line 61
            echo $context["tabs"]->getsubscription_tab("read", "~", "read", (isset($context["filter"]) ? $context["filter"] : $this->getContext($context, "filter")), $this->getAttribute((isset($context["total_subscribed_forums"]) ? $context["total_subscribed_forums"] : $this->getContext($context, "total_subscribed_forums")), "count_read", array(), "array"), null, null);
        }
        // line 63
        echo "</ul>
\t\t</div>
\t</section>";
        // line 67
        echo $this->env->getExtension('knp_pagination')->render((isset($context["pager"]) ? $context["pager"] : $this->getContext($context, "pager")));
        // line 69
        echo "<section class=\"clearfix\">
\t\t<table class=\"table table-striped table-hover\">
\t\t\t<thead>
\t\t\t\t<tr>
\t\t\t\t\t<th class=\"center\" style=\"width:18px;\"></th>
\t\t\t\t\t<th class=\"center\" style=\"width:18px;\"></th>
\t\t\t\t\t<th class=\"left\">";
        // line 75
        echo twig_escape_filter($this->env, $this->env->getExtension('translator')->trans("board.topic-th", array(), "CCDNForumForumBundle"), "html", null, true);
        echo "</th>
\t\t\t\t\t<th class=\"center\" style=\"width: 100px;\">";
        // line 76
        echo twig_escape_filter($this->env, $this->env->getExtension('translator')->trans("board.reply-count-th", array(), "CCDNForumForumBundle"), "html", null, true);
        echo "</th>
\t\t\t\t\t<th class=\"center\" style=\"width: 100px;\">";
        // line 77
        echo twig_escape_filter($this->env, $this->env->getExtension('translator')->trans("board.view-count-th", array(), "CCDNForumForumBundle"), "html", null, true);
        echo "</th>
\t\t\t\t\t<th class=\"center\" style=\"width: 170px;\">";
        // line 78
        echo twig_escape_filter($this->env, $this->env->getExtension('translator')->trans("board.last-post-th", array(), "CCDNForumForumBundle"), "html", null, true);
        echo "</th>
\t\t\t\t</tr>
\t\t\t</thead>
\t\t\t<tbody>";
        // line 82
        $context['_parent'] = (array) $context;
        $context['_seq'] = twig_ensure_traversable($this->getAttribute((isset($context["pager"]) ? $context["pager"] : $this->getContext($context, "pager")), "getItems", array(), "method"));
        $context['_iterated'] = false;
        $context['loop'] = array(
          'parent' => $context['_parent'],
          'index0' => 0,
          'index'  => 1,
          'first'  => true,
        );
        if (is_array($context['_seq']) || (is_object($context['_seq']) && $context['_seq'] instanceof Countable)) {
            $length = count($context['_seq']);
            $context['loop']['revindex0'] = $length - 1;
            $context['loop']['revindex'] = $length;
            $context['loop']['length'] = $length;
            $context['loop']['last'] = 1 === $length;
        }
        foreach ($context['_seq'] as $context["row"] => $context["subscription"]) {
            // line 83
            $context["topic"] = $this->getAttribute((isset($context["subscription"]) ? $context["subscription"] : $this->getContext($context, "subscription")), "getTopic");
            // line 85
            $this->env->loadTemplate("CCDNForumForumBundle:User:Subscription/Partial/item_topic_list.html.twig")->display($context);
            $context['_iterated'] = true;
            ++$context['loop']['index0'];
            ++$context['loop']['index'];
            $context['loop']['first'] = false;
            if (isset($context['loop']['length'])) {
                --$context['loop']['revindex0'];
                --$context['loop']['revindex'];
                $context['loop']['last'] = 0 === $context['loop']['revindex0'];
            }
        }
        if (!$context['_iterated']) {
            // line 87
            echo "<tr>
\t\t\t\t\t\t<td class=\"text-center\" colspan=\"6\">
\t\t\t\t\t\t\t<span class=\"lead\">";
            // line 90
            echo twig_escape_filter($this->env, $this->env->getExtension('translator')->trans("subscription.no-topics", array(), "CCDNForumForumBundle"), "html", null, true);
            // line 91
            echo "</span>
\t\t\t\t\t\t</td>
\t\t\t\t\t</tr>";
        }
        $_parent = $context['_parent'];
        unset($context['_seq'], $context['_iterated'], $context['row'], $context['subscription'], $context['_parent'], $context['loop']);
        $context = array_intersect_key($context, $_parent) + $_parent;
        // line 95
        echo "</tbody>
\t\t</table>
\t</section>";
        // line 99
        echo $this->env->getExtension('knp_pagination')->render((isset($context["pager"]) ? $context["pager"] : $this->getContext($context, "pager")));
        echo trim(preg_replace('/>\s+</', '><', ob_get_clean()));
    }

    // line 16
    public function getsubscription_tab($_label = null, $_forum_name = null, $_filter_key = null, $_filter_value = null, $_count_read = null, $_count_unread = null, $_count_total = null)
    {
        $context = $this->env->mergeGlobals(array(
            "label" => $_label,
            "forum_name" => $_forum_name,
            "filter_key" => $_filter_key,
            "filter_value" => $_filter_value,
            "count_read" => $_count_read,
            "count_unread" => $_count_unread,
            "count_total" => $_count_total,
        ));

        $blocks = array();

        ob_start();
        try {
            // line 17
            if (((isset($context["filter_key"]) ? $context["filter_key"] : $this->getContext($context, "filter_key")) == (isset($context["filter_value"]) ? $context["filter_value"] : $this->getContext($context, "filter_value")))) {
                // line 18
                echo "<li class=\"active\">";
            } else {
                // line 20
                echo "<li>";
            }
            // line 22
            echo "<a href=\"";
            echo twig_escape_filter($this->env, $this->env->getExtension('routing')->getPath("ccdn_forum_user_subscription_index", array("forumName" => (isset($context["forum_name"]) ? $context["forum_name"] : $this->getContext($context, "forum_name")), "filter" => (isset($context["filter_key"]) ? $context["filter_key"] : $this->getContext($context, "filter_key")))), "html", null, true);
            echo "\">";
            // line 23
            echo twig_escape_filter($this->env, (isset($context["label"]) ? $context["label"] : $this->getContext($context, "label")), "html", null, true);
            // line 25
            echo "&nbsp;

\t\t\t<span class=\"badge\">";
            // line 28
            if (((!(null === (isset($context["count_unread"]) ? $context["count_unread"] : $this->getContext($context, "count_unread")))) && (!(null === (isset($context["count_total"]) ? $context["count_total"] : $this->getContext($context, "count_total")))))) {
                // line 29
                echo twig_escape_filter($this->env, (isset($context["count_unread"]) ? $context["count_unread"] : $this->getContext($context, "count_unread")), "html", null, true);
                // line 30
                echo "&nbsp;/&nbsp;";
                // line 31
                echo twig_escape_filter($this->env, (isset($context["count_total"]) ? $context["count_total"] : $this->getContext($context, "count_total")), "html", null, true);
            } else {
                // line 33
                if ((!(null === (isset($context["count_unread"]) ? $context["count_unread"] : $this->getContext($context, "count_unread"))))) {
                    // line 34
                    echo twig_escape_filter($this->env, (isset($context["count_unread"]) ? $context["count_unread"] : $this->getContext($context, "count_unread")), "html", null, true);
                }
                // line 37
                if ((!(null === (isset($context["count_read"]) ? $context["count_read"] : $this->getContext($context, "count_read"))))) {
                    // line 38
                    echo twig_escape_filter($this->env, (isset($context["count_read"]) ? $context["count_read"] : $this->getContext($context, "count_read")), "html", null, true);
                }
            }
            // line 41
            echo "</span>
\t\t</a>
\t</li>";
        } catch (Exception $e) {
            ob_end_clean();

            throw $e;
        }

        return ('' === $tmp = ob_get_clean()) ? '' : new Twig_Markup($tmp, $this->env->getCharset());
    }

    public function getTemplateName()
    {
        return "CCDNForumForumBundle:User/Subscription:show.html.twig";
    }

    public function isTraitable()
    {
        return false;
    }

    public function getDebugInfo()
    {
        return array (  205 => 30,  234 => 94,  297 => 118,  956 => 271,  953 => 270,  946 => 302,  942 => 300,  933 => 296,  925 => 292,  917 => 291,  914 => 290,  912 => 289,  909 => 288,  901 => 285,  898 => 284,  890 => 281,  887 => 280,  879 => 277,  870 => 274,  868 => 273,  863 => 269,  853 => 261,  848 => 258,  840 => 253,  834 => 249,  832 => 248,  822 => 244,  820 => 243,  816 => 241,  810 => 238,  807 => 237,  805 => 236,  802 => 235,  799 => 234,  791 => 262,  788 => 233,  773 => 264,  771 => 232,  768 => 231,  765 => 230,  757 => 221,  743 => 217,  738 => 214,  732 => 213,  720 => 211,  713 => 209,  688 => 202,  682 => 201,  679 => 200,  673 => 198,  668 => 197,  665 => 196,  663 => 195,  660 => 194,  657 => 193,  647 => 191,  632 => 187,  629 => 186,  626 => 184,  610 => 181,  603 => 179,  600 => 178,  588 => 175,  570 => 164,  561 => 161,  554 => 224,  522 => 156,  479 => 135,  471 => 129,  451 => 120,  418 => 112,  373 => 102,  370 => 101,  356 => 126,  624 => 224,  620 => 223,  612 => 220,  601 => 216,  594 => 176,  585 => 209,  580 => 207,  574 => 205,  572 => 204,  566 => 203,  559 => 201,  551 => 221,  545 => 198,  526 => 190,  507 => 156,  497 => 156,  485 => 124,  463 => 117,  447 => 113,  424 => 114,  412 => 126,  410 => 110,  406 => 111,  404 => 90,  401 => 89,  391 => 163,  376 => 103,  369 => 148,  359 => 144,  333 => 132,  329 => 130,  326 => 86,  318 => 86,  261 => 104,  195 => 23,  306 => 95,  303 => 123,  292 => 119,  287 => 77,  280 => 87,  178 => 73,  12 => 36,  118 => 65,  778 => 267,  763 => 244,  760 => 222,  748 => 242,  745 => 241,  742 => 240,  736 => 238,  734 => 237,  717 => 210,  714 => 232,  711 => 231,  703 => 226,  700 => 205,  653 => 218,  650 => 192,  644 => 190,  633 => 209,  616 => 182,  599 => 215,  595 => 205,  587 => 203,  584 => 173,  581 => 201,  578 => 200,  573 => 198,  546 => 175,  534 => 162,  531 => 225,  521 => 182,  513 => 230,  499 => 173,  475 => 169,  473 => 168,  468 => 128,  454 => 121,  448 => 119,  445 => 152,  429 => 148,  422 => 147,  399 => 139,  396 => 138,  348 => 118,  345 => 116,  340 => 91,  330 => 103,  307 => 123,  300 => 122,  291 => 115,  286 => 115,  190 => 72,  321 => 128,  295 => 100,  274 => 111,  242 => 82,  236 => 92,  70 => 37,  1414 => 421,  1408 => 419,  1402 => 417,  1400 => 416,  1398 => 415,  1394 => 414,  1385 => 413,  1383 => 412,  1380 => 411,  1367 => 405,  1361 => 403,  1355 => 401,  1353 => 400,  1351 => 399,  1347 => 398,  1341 => 397,  1339 => 396,  1336 => 395,  1323 => 389,  1317 => 387,  1311 => 385,  1309 => 384,  1307 => 383,  1303 => 382,  1297 => 381,  1291 => 380,  1287 => 379,  1283 => 378,  1279 => 377,  1273 => 376,  1271 => 375,  1268 => 374,  1256 => 369,  1251 => 368,  1249 => 367,  1246 => 366,  1237 => 360,  1231 => 358,  1228 => 357,  1223 => 356,  1221 => 355,  1218 => 354,  1211 => 349,  1202 => 347,  1198 => 346,  1195 => 345,  1192 => 344,  1190 => 343,  1187 => 342,  1179 => 338,  1177 => 337,  1174 => 336,  1168 => 332,  1162 => 330,  1159 => 329,  1157 => 328,  1154 => 327,  1145 => 322,  1143 => 321,  1118 => 320,  1115 => 319,  1112 => 318,  1109 => 317,  1106 => 316,  1103 => 315,  1100 => 314,  1098 => 313,  1095 => 312,  1088 => 308,  1084 => 307,  1079 => 306,  1077 => 305,  1074 => 304,  1067 => 299,  1064 => 298,  1056 => 293,  1053 => 292,  1051 => 291,  1048 => 290,  1040 => 285,  1036 => 284,  1032 => 283,  1029 => 282,  1027 => 281,  1024 => 280,  1016 => 276,  1014 => 272,  1012 => 271,  1009 => 270,  1004 => 266,  982 => 261,  979 => 260,  976 => 259,  973 => 258,  970 => 257,  967 => 256,  964 => 255,  961 => 254,  958 => 253,  955 => 252,  952 => 251,  950 => 269,  947 => 249,  939 => 243,  936 => 297,  934 => 241,  931 => 295,  923 => 236,  920 => 235,  918 => 234,  915 => 233,  903 => 286,  900 => 228,  897 => 227,  894 => 226,  892 => 282,  889 => 224,  881 => 278,  878 => 219,  876 => 276,  873 => 217,  865 => 272,  862 => 212,  860 => 268,  857 => 267,  849 => 206,  846 => 205,  844 => 204,  841 => 203,  833 => 199,  830 => 198,  828 => 246,  825 => 196,  817 => 192,  814 => 191,  812 => 190,  809 => 189,  801 => 185,  798 => 184,  796 => 233,  793 => 182,  785 => 232,  783 => 177,  780 => 303,  772 => 248,  769 => 247,  767 => 246,  764 => 169,  756 => 165,  753 => 220,  751 => 163,  749 => 218,  746 => 161,  739 => 239,  729 => 235,  724 => 154,  721 => 153,  715 => 151,  712 => 150,  710 => 149,  707 => 208,  699 => 142,  697 => 141,  696 => 204,  695 => 139,  694 => 138,  689 => 137,  680 => 134,  675 => 132,  662 => 125,  658 => 124,  654 => 123,  649 => 122,  643 => 120,  640 => 211,  638 => 210,  619 => 183,  617 => 112,  614 => 111,  598 => 107,  596 => 106,  593 => 105,  576 => 199,  564 => 162,  557 => 96,  550 => 187,  547 => 93,  527 => 91,  515 => 305,  512 => 84,  509 => 228,  503 => 81,  496 => 172,  493 => 143,  478 => 74,  467 => 72,  456 => 68,  450 => 114,  428 => 116,  414 => 144,  408 => 109,  390 => 136,  388 => 42,  377 => 129,  371 => 35,  363 => 32,  350 => 26,  342 => 23,  335 => 133,  332 => 88,  316 => 132,  313 => 84,  290 => 90,  276 => 110,  266 => 106,  263 => 105,  255 => 353,  245 => 83,  207 => 31,  194 => 52,  76 => 10,  200 => 75,  184 => 75,  58 => 30,  170 => 87,  563 => 202,  560 => 191,  558 => 160,  553 => 188,  549 => 182,  543 => 174,  537 => 159,  532 => 192,  528 => 160,  525 => 157,  523 => 189,  518 => 180,  514 => 167,  511 => 166,  508 => 165,  501 => 154,  491 => 157,  487 => 156,  460 => 123,  455 => 115,  449 => 138,  442 => 151,  439 => 150,  436 => 132,  433 => 149,  426 => 58,  420 => 146,  415 => 127,  411 => 143,  405 => 108,  403 => 48,  380 => 130,  366 => 150,  354 => 101,  331 => 135,  325 => 94,  308 => 126,  304 => 122,  272 => 108,  267 => 105,  249 => 74,  216 => 86,  155 => 63,  146 => 10,  126 => 47,  124 => 68,  188 => 20,  181 => 81,  161 => 99,  320 => 84,  317 => 127,  311 => 128,  288 => 114,  284 => 114,  279 => 77,  275 => 86,  256 => 103,  250 => 99,  237 => 92,  232 => 91,  222 => 85,  191 => 22,  153 => 80,  150 => 34,  110 => 82,  692 => 399,  683 => 223,  678 => 133,  676 => 199,  666 => 222,  661 => 220,  656 => 219,  652 => 376,  645 => 369,  641 => 189,  635 => 188,  631 => 364,  625 => 361,  615 => 354,  607 => 180,  597 => 177,  590 => 204,  583 => 334,  579 => 332,  577 => 206,  575 => 328,  569 => 325,  565 => 324,  555 => 200,  548 => 176,  540 => 160,  536 => 194,  529 => 159,  524 => 90,  516 => 294,  510 => 178,  504 => 155,  500 => 291,  495 => 158,  490 => 142,  486 => 286,  482 => 136,  470 => 121,  464 => 125,  459 => 116,  452 => 268,  434 => 118,  421 => 90,  417 => 145,  400 => 47,  385 => 159,  361 => 124,  344 => 24,  339 => 191,  324 => 110,  310 => 83,  302 => 79,  296 => 121,  282 => 161,  259 => 103,  244 => 96,  231 => 69,  226 => 131,  215 => 37,  186 => 69,  152 => 85,  114 => 63,  104 => 78,  358 => 123,  351 => 141,  347 => 140,  343 => 92,  338 => 113,  327 => 131,  323 => 85,  319 => 124,  315 => 98,  301 => 80,  299 => 8,  293 => 90,  289 => 117,  281 => 113,  277 => 112,  271 => 110,  265 => 106,  262 => 81,  260 => 363,  257 => 103,  251 => 101,  248 => 116,  239 => 93,  228 => 88,  225 => 86,  213 => 82,  211 => 83,  197 => 25,  174 => 65,  148 => 83,  134 => 50,  127 => 62,  270 => 84,  253 => 78,  233 => 304,  212 => 34,  210 => 33,  206 => 57,  202 => 76,  198 => 80,  192 => 73,  185 => 18,  180 => 93,  175 => 89,  172 => 70,  167 => 94,  165 => 69,  160 => 91,  137 => 70,  113 => 56,  100 => 77,  90 => 44,  81 => 13,  65 => 28,  129 => 63,  97 => 27,  84 => 69,  34 => 14,  53 => 24,  77 => 35,  20 => 11,  23 => 3,  480 => 75,  474 => 122,  469 => 158,  461 => 70,  457 => 153,  453 => 151,  444 => 263,  440 => 148,  437 => 61,  435 => 146,  430 => 255,  427 => 143,  423 => 57,  413 => 241,  409 => 132,  407 => 238,  402 => 107,  398 => 88,  393 => 168,  387 => 110,  384 => 106,  381 => 105,  379 => 104,  374 => 128,  368 => 126,  365 => 141,  362 => 148,  360 => 128,  355 => 122,  341 => 131,  337 => 90,  322 => 93,  314 => 88,  312 => 125,  309 => 82,  305 => 124,  298 => 101,  294 => 90,  285 => 78,  283 => 97,  278 => 111,  268 => 373,  264 => 105,  258 => 72,  252 => 102,  247 => 98,  241 => 96,  229 => 73,  220 => 84,  214 => 63,  177 => 102,  169 => 95,  140 => 62,  132 => 66,  128 => 83,  107 => 57,  61 => 22,  273 => 85,  269 => 109,  254 => 102,  243 => 97,  240 => 72,  238 => 95,  235 => 63,  230 => 89,  227 => 92,  224 => 39,  221 => 41,  219 => 87,  217 => 38,  208 => 124,  204 => 82,  179 => 67,  159 => 196,  143 => 87,  135 => 68,  119 => 57,  102 => 49,  71 => 59,  67 => 31,  63 => 28,  59 => 21,  38 => 15,  94 => 48,  89 => 48,  85 => 16,  75 => 61,  68 => 57,  56 => 50,  87 => 47,  21 => 2,  26 => 4,  93 => 52,  88 => 43,  78 => 63,  46 => 12,  27 => 3,  44 => 11,  31 => 10,  28 => 29,  201 => 28,  196 => 52,  183 => 17,  171 => 81,  166 => 16,  163 => 92,  158 => 82,  156 => 81,  151 => 77,  142 => 30,  138 => 61,  136 => 72,  121 => 58,  117 => 57,  105 => 56,  91 => 25,  62 => 54,  49 => 22,  24 => 4,  25 => 4,  19 => 1,  79 => 43,  72 => 38,  69 => 32,  47 => 19,  40 => 14,  37 => 11,  22 => 2,  246 => 67,  157 => 95,  145 => 78,  139 => 77,  131 => 65,  123 => 50,  120 => 61,  115 => 56,  111 => 53,  108 => 53,  101 => 53,  98 => 54,  96 => 76,  83 => 45,  74 => 35,  66 => 56,  55 => 23,  52 => 27,  50 => 23,  43 => 14,  41 => 33,  35 => 6,  32 => 5,  29 => 8,  209 => 82,  203 => 29,  199 => 85,  193 => 51,  189 => 52,  187 => 77,  182 => 74,  176 => 72,  173 => 88,  168 => 84,  164 => 61,  162 => 85,  154 => 86,  149 => 91,  147 => 90,  144 => 26,  141 => 76,  133 => 67,  130 => 85,  125 => 61,  122 => 60,  116 => 64,  112 => 55,  109 => 52,  106 => 57,  103 => 55,  99 => 48,  95 => 47,  92 => 75,  86 => 41,  82 => 67,  80 => 36,  73 => 60,  64 => 55,  60 => 53,  57 => 24,  54 => 48,  51 => 47,  48 => 16,  45 => 36,  42 => 10,  39 => 9,  36 => 12,  33 => 12,  30 => 7,);
    }
}
