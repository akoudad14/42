<?php

/* HackzillaTicketBundle:Ticket:index.html.twig */
class __TwigTemplate_69c79b515cef3f4b9d8553345b7fe0c30d4d7a59a276ed611f1b444387d512cf extends Twig_Template
{
    public function __construct(Twig_Environment $env)
    {
        parent::__construct($env);

        $this->parent = $this->env->loadTemplate("HackzillaTicketBundle::layout.html.twig");

        $this->blocks = array(
            'hackzilla_ticket_content' => array($this, 'block_hackzilla_ticket_content'),
        );
    }

    protected function doGetParent(array $context)
    {
        return "HackzillaTicketBundle::layout.html.twig";
    }

    protected function doDisplay(array $context, array $blocks = array())
    {
        $this->parent->display($context, array_merge($this->blocks, $blocks));
    }

    // line 3
    public function block_hackzilla_ticket_content($context, array $blocks = array())
    {
        // line 4
        echo "<a href=\"";
        echo $this->env->getExtension('routing')->getPath("hackzilla_ticket_new");
        echo "\" class=\"btn btn-primary pull-right\">";
        echo twig_escape_filter($this->env, $this->env->getExtension('translator')->trans("BUTTON_NEW"), "html", null, true);
        echo "</a>
<h1>";
        // line 5
        echo twig_escape_filter($this->env, $this->env->getExtension('translator')->trans("HEADING_TICKET_LIST"), "html", null, true);
        echo "</h1>";
        // line 7
        if (((isset($context["ticketState"]) ? $context["ticketState"] : null) == $this->env->getExtension('translator')->trans("STATUS_CLOSED"))) {
            // line 8
            echo "        ";
            ob_start();
            echo "<a href=\"?state=";
            echo twig_escape_filter($this->env, $this->env->getExtension('translator')->trans("STATUS_OPEN"), "html", null, true);
            echo "\">";
            echo twig_escape_filter($this->env, $this->env->getExtension('translator')->trans("STATUS_OPEN"), "html", null, true);
            echo "</a>";
            $context["state"] = ('' === $tmp = ob_get_clean()) ? '' : new Twig_Markup($tmp, $this->env->getCharset());
        } else {
            // line 10
            echo "        ";
            ob_start();
            echo "<a href=\"?state=";
            echo twig_escape_filter($this->env, $this->env->getExtension('translator')->trans("STATUS_CLOSED"), "html", null, true);
            echo "\">";
            echo twig_escape_filter($this->env, $this->env->getExtension('translator')->trans("STATUS_CLOSED"), "html", null, true);
            echo "</a>";
            $context["state"] = ('' === $tmp = ob_get_clean()) ? '' : new Twig_Markup($tmp, $this->env->getCharset());
        }
        // line 13
        echo "<p>";
        echo $this->env->getExtension('translator')->trans("BUTTON_TOGGLE_STATE", array("%state%" => (isset($context["state"]) ? $context["state"] : null)));
        echo "</p>

<table class=\"table table-bordered table-striped\">
    <thead>
        <tr>
            <th>";
        // line 18
        echo $this->env->getExtension('knp_pagination')->sortable((isset($context["pagination"]) ? $context["pagination"] : null), $this->env->getExtension('translator')->trans("HEADING_TICKET"), "t.id");
        echo "</th>
            <th";
        // line 19
        if ($this->getAttribute((isset($context["pagination"]) ? $context["pagination"] : null), "isSorted", array(0 => "t.subject"), "method")) {
            echo " class=\"sorted\"";
        }
        echo ">";
        echo $this->env->getExtension('knp_pagination')->sortable((isset($context["pagination"]) ? $context["pagination"] : null), $this->env->getExtension('translator')->trans("HEADING_SUBJECT"), "t.subject");
        echo "</th>
            <th";
        // line 20
        if ($this->getAttribute((isset($context["pagination"]) ? $context["pagination"] : null), "isSorted", array(0 => "t.status"), "method")) {
            echo " class=\"sorted\"";
        }
        echo ">";
        echo $this->env->getExtension('knp_pagination')->sortable((isset($context["pagination"]) ? $context["pagination"] : null), $this->env->getExtension('translator')->trans("HEADING_STATUS"), "t.status");
        echo "</th>
            <th";
        // line 21
        if ($this->getAttribute((isset($context["pagination"]) ? $context["pagination"] : null), "isSorted", array(0 => "t.priority"), "method")) {
            echo " class=\"sorted\"";
        }
        echo ">";
        echo $this->env->getExtension('knp_pagination')->sortable((isset($context["pagination"]) ? $context["pagination"] : null), $this->env->getExtension('translator')->trans("HEADING_PRIORITY"), "t.priority");
        echo "</th>
            <th";
        // line 22
        if ($this->getAttribute((isset($context["pagination"]) ? $context["pagination"] : null), "isSorted", array(0 => "t.modified"), "method")) {
            echo " class=\"sorted\"";
        }
        echo ">";
        echo $this->env->getExtension('knp_pagination')->sortable((isset($context["pagination"]) ? $context["pagination"] : null), $this->env->getExtension('translator')->trans("HEADING_MODIFIED"), "t.lastMessage");
        echo "</th>
            <th";
        // line 23
        if ($this->getAttribute((isset($context["pagination"]) ? $context["pagination"] : null), "isSorted", array(0 => "t.created"), "method")) {
            echo " class=\"sorted\"";
        }
        echo ">";
        echo $this->env->getExtension('knp_pagination')->sortable((isset($context["pagination"]) ? $context["pagination"] : null), $this->env->getExtension('translator')->trans("HEADING_CREATED"), "t.createdAt");
        echo "</th>
        </tr>
    </thead>
    <tbody>
    ";
        // line 27
        $context['_parent'] = (array) $context;
        $context['_seq'] = twig_ensure_traversable((isset($context["pagination"]) ? $context["pagination"] : null));
        $context['_iterated'] = false;
        foreach ($context['_seq'] as $context["_key"] => $context["entity"]) {
            // line 28
            echo "        <tr>
            <td><a href=\"";
            // line 29
            echo twig_escape_filter($this->env, $this->env->getExtension('routing')->getPath("hackzilla_ticket_show", array("id" => $this->getAttribute((isset($context["entity"]) ? $context["entity"] : null), "id"))), "html", null, true);
            echo "\">";
            echo twig_escape_filter($this->env, $this->getAttribute((isset($context["entity"]) ? $context["entity"] : null), "id"), "html", null, true);
            echo "</a></td>
            <td><a href=\"";
            // line 30
            echo twig_escape_filter($this->env, $this->env->getExtension('routing')->getPath("hackzilla_ticket_show", array("id" => $this->getAttribute((isset($context["entity"]) ? $context["entity"] : null), "id"))), "html", null, true);
            echo "\">";
            echo twig_escape_filter($this->env, $this->getAttribute((isset($context["entity"]) ? $context["entity"] : null), "subject"), "html", null, true);
            echo "</a></td>
            <td>";
            // line 31
            echo twig_escape_filter($this->env, $this->env->getExtension('translator')->trans($this->getAttribute((isset($context["entity"]) ? $context["entity"] : null), "statusString")), "html", null, true);
            echo "</td>
            <td>";
            // line 32
            echo twig_escape_filter($this->env, $this->env->getExtension('translator')->trans($this->getAttribute((isset($context["entity"]) ? $context["entity"] : null), "priorityString")), "html", null, true);
            echo "</td>
            <td>";
            // line 33
            if ($this->getAttribute((isset($context["entity"]) ? $context["entity"] : null), "lastMessage")) {
                echo twig_escape_filter($this->env, twig_date_format_filter($this->env, $this->getAttribute((isset($context["entity"]) ? $context["entity"] : null), "lastMessage"), "Y-m-d H:i:s"), "html", null, true);
            }
            echo "</td>
            <td>";
            // line 34
            if ($this->getAttribute((isset($context["entity"]) ? $context["entity"] : null), "createdAt")) {
                echo twig_escape_filter($this->env, twig_date_format_filter($this->env, $this->getAttribute((isset($context["entity"]) ? $context["entity"] : null), "createdAt"), "Y-m-d H:i:s"), "html", null, true);
            }
            echo "</td>
        </tr>
    ";
            $context['_iterated'] = true;
        }
        if (!$context['_iterated']) {
            // line 37
            echo "        <tr>
            <td colspan=\"6\">";
            // line 38
            echo twig_escape_filter($this->env, $this->env->getExtension('translator')->trans("MESSAGE_NO_TICKETS"), "html", null, true);
            echo ".</td>
        </tr>
    ";
        }
        $_parent = $context['_parent'];
        unset($context['_seq'], $context['_iterated'], $context['_key'], $context['entity'], $context['_parent'], $context['loop']);
        $context = array_intersect_key($context, $_parent) + $_parent;
        // line 41
        echo "    </tbody>
</table>
<div class=\"navigation\">
    ";
        // line 44
        echo $this->env->getExtension('knp_pagination')->render((isset($context["pagination"]) ? $context["pagination"] : null));
        echo "
</div>

";
    }

    public function getTemplateName()
    {
        return "HackzillaTicketBundle:Ticket:index.html.twig";
    }

    public function isTraitable()
    {
        return false;
    }

    public function getDebugInfo()
    {
        return array (  956 => 271,  953 => 270,  946 => 302,  942 => 300,  933 => 296,  925 => 292,  917 => 291,  914 => 290,  912 => 289,  909 => 288,  901 => 285,  898 => 284,  890 => 281,  887 => 280,  879 => 277,  870 => 274,  868 => 273,  863 => 269,  853 => 261,  848 => 258,  840 => 253,  834 => 249,  832 => 248,  822 => 244,  820 => 243,  816 => 241,  810 => 238,  807 => 237,  805 => 236,  802 => 235,  799 => 234,  791 => 262,  788 => 233,  773 => 264,  771 => 232,  768 => 231,  765 => 230,  757 => 221,  743 => 217,  738 => 214,  732 => 213,  720 => 211,  713 => 209,  688 => 202,  682 => 201,  679 => 200,  673 => 198,  668 => 197,  665 => 196,  663 => 195,  660 => 194,  657 => 193,  647 => 191,  632 => 187,  629 => 186,  626 => 184,  610 => 181,  603 => 179,  600 => 178,  588 => 175,  570 => 164,  561 => 161,  554 => 224,  522 => 156,  479 => 135,  471 => 129,  451 => 120,  418 => 112,  373 => 102,  370 => 101,  356 => 126,  624 => 224,  620 => 223,  612 => 220,  601 => 216,  594 => 176,  585 => 209,  580 => 207,  574 => 205,  572 => 204,  566 => 203,  559 => 201,  551 => 221,  545 => 198,  526 => 190,  507 => 156,  497 => 156,  485 => 124,  463 => 117,  447 => 113,  424 => 114,  412 => 126,  410 => 110,  406 => 111,  404 => 90,  401 => 89,  391 => 163,  376 => 103,  369 => 148,  359 => 144,  333 => 132,  329 => 130,  326 => 86,  318 => 86,  261 => 50,  195 => 54,  306 => 95,  303 => 94,  292 => 91,  287 => 77,  280 => 87,  178 => 80,  12 => 36,  118 => 49,  778 => 267,  763 => 244,  760 => 222,  748 => 242,  745 => 241,  742 => 240,  736 => 238,  734 => 237,  717 => 210,  714 => 232,  711 => 231,  703 => 226,  700 => 205,  653 => 218,  650 => 192,  644 => 190,  633 => 209,  616 => 182,  599 => 215,  595 => 205,  587 => 203,  584 => 173,  581 => 201,  578 => 200,  573 => 198,  546 => 175,  534 => 162,  531 => 225,  521 => 182,  513 => 230,  499 => 173,  475 => 169,  473 => 168,  468 => 128,  454 => 121,  448 => 119,  445 => 152,  429 => 148,  422 => 147,  399 => 139,  396 => 138,  348 => 118,  345 => 116,  340 => 91,  330 => 103,  307 => 82,  300 => 93,  291 => 80,  286 => 98,  190 => 49,  321 => 100,  295 => 100,  274 => 53,  242 => 82,  236 => 42,  70 => 29,  1414 => 421,  1408 => 419,  1402 => 417,  1400 => 416,  1398 => 415,  1394 => 414,  1385 => 413,  1383 => 412,  1380 => 411,  1367 => 405,  1361 => 403,  1355 => 401,  1353 => 400,  1351 => 399,  1347 => 398,  1341 => 397,  1339 => 396,  1336 => 395,  1323 => 389,  1317 => 387,  1311 => 385,  1309 => 384,  1307 => 383,  1303 => 382,  1297 => 381,  1291 => 380,  1287 => 379,  1283 => 378,  1279 => 377,  1273 => 376,  1271 => 375,  1268 => 374,  1256 => 369,  1251 => 368,  1249 => 367,  1246 => 366,  1237 => 360,  1231 => 358,  1228 => 357,  1223 => 356,  1221 => 355,  1218 => 354,  1211 => 349,  1202 => 347,  1198 => 346,  1195 => 345,  1192 => 344,  1190 => 343,  1187 => 342,  1179 => 338,  1177 => 337,  1174 => 336,  1168 => 332,  1162 => 330,  1159 => 329,  1157 => 328,  1154 => 327,  1145 => 322,  1143 => 321,  1118 => 320,  1115 => 319,  1112 => 318,  1109 => 317,  1106 => 316,  1103 => 315,  1100 => 314,  1098 => 313,  1095 => 312,  1088 => 308,  1084 => 307,  1079 => 306,  1077 => 305,  1074 => 304,  1067 => 299,  1064 => 298,  1056 => 293,  1053 => 292,  1051 => 291,  1048 => 290,  1040 => 285,  1036 => 284,  1032 => 283,  1029 => 282,  1027 => 281,  1024 => 280,  1016 => 276,  1014 => 272,  1012 => 271,  1009 => 270,  1004 => 266,  982 => 261,  979 => 260,  976 => 259,  973 => 258,  970 => 257,  967 => 256,  964 => 255,  961 => 254,  958 => 253,  955 => 252,  952 => 251,  950 => 269,  947 => 249,  939 => 243,  936 => 297,  934 => 241,  931 => 295,  923 => 236,  920 => 235,  918 => 234,  915 => 233,  903 => 286,  900 => 228,  897 => 227,  894 => 226,  892 => 282,  889 => 224,  881 => 278,  878 => 219,  876 => 276,  873 => 217,  865 => 272,  862 => 212,  860 => 268,  857 => 267,  849 => 206,  846 => 205,  844 => 204,  841 => 203,  833 => 199,  830 => 198,  828 => 246,  825 => 196,  817 => 192,  814 => 191,  812 => 190,  809 => 189,  801 => 185,  798 => 184,  796 => 233,  793 => 182,  785 => 232,  783 => 177,  780 => 303,  772 => 248,  769 => 247,  767 => 246,  764 => 169,  756 => 165,  753 => 220,  751 => 163,  749 => 218,  746 => 161,  739 => 239,  729 => 235,  724 => 154,  721 => 153,  715 => 151,  712 => 150,  710 => 149,  707 => 208,  699 => 142,  697 => 141,  696 => 204,  695 => 139,  694 => 138,  689 => 137,  680 => 134,  675 => 132,  662 => 125,  658 => 124,  654 => 123,  649 => 122,  643 => 120,  640 => 211,  638 => 210,  619 => 183,  617 => 112,  614 => 111,  598 => 107,  596 => 106,  593 => 105,  576 => 199,  564 => 162,  557 => 96,  550 => 187,  547 => 93,  527 => 91,  515 => 305,  512 => 84,  509 => 228,  503 => 81,  496 => 172,  493 => 143,  478 => 74,  467 => 72,  456 => 68,  450 => 114,  428 => 116,  414 => 144,  408 => 109,  390 => 136,  388 => 42,  377 => 129,  371 => 35,  363 => 32,  350 => 26,  342 => 23,  335 => 133,  332 => 88,  316 => 16,  313 => 84,  290 => 90,  276 => 395,  266 => 366,  263 => 365,  255 => 353,  245 => 83,  207 => 33,  194 => 52,  76 => 19,  200 => 31,  184 => 48,  157 => 56,  83 => 44,  58 => 32,  170 => 77,  139 => 31,  563 => 202,  560 => 191,  558 => 160,  553 => 188,  549 => 182,  543 => 174,  537 => 159,  532 => 192,  528 => 160,  525 => 157,  523 => 189,  518 => 180,  514 => 167,  511 => 166,  508 => 165,  501 => 154,  491 => 157,  487 => 156,  460 => 123,  455 => 115,  449 => 138,  442 => 151,  439 => 150,  436 => 132,  433 => 149,  426 => 58,  420 => 146,  415 => 127,  411 => 143,  405 => 108,  403 => 48,  380 => 130,  366 => 150,  354 => 101,  331 => 96,  325 => 94,  308 => 13,  304 => 81,  272 => 91,  267 => 78,  249 => 74,  216 => 35,  155 => 75,  146 => 34,  126 => 63,  124 => 28,  188 => 88,  181 => 81,  161 => 75,  320 => 84,  317 => 107,  311 => 83,  288 => 79,  284 => 76,  279 => 77,  275 => 86,  256 => 79,  250 => 44,  237 => 71,  232 => 78,  222 => 66,  191 => 26,  153 => 34,  150 => 34,  145 => 53,  110 => 45,  692 => 399,  683 => 223,  678 => 133,  676 => 199,  666 => 222,  661 => 220,  656 => 219,  652 => 376,  645 => 369,  641 => 189,  635 => 188,  631 => 364,  625 => 361,  615 => 354,  607 => 180,  597 => 177,  590 => 204,  583 => 334,  579 => 332,  577 => 206,  575 => 328,  569 => 325,  565 => 324,  555 => 200,  548 => 176,  540 => 160,  536 => 194,  529 => 159,  524 => 90,  516 => 294,  510 => 178,  504 => 155,  500 => 291,  495 => 158,  490 => 142,  486 => 286,  482 => 136,  470 => 121,  464 => 125,  459 => 116,  452 => 268,  434 => 118,  421 => 90,  417 => 145,  400 => 47,  385 => 159,  361 => 124,  344 => 24,  339 => 191,  324 => 110,  310 => 83,  302 => 79,  296 => 151,  282 => 161,  259 => 87,  244 => 43,  231 => 69,  226 => 131,  215 => 280,  186 => 51,  152 => 74,  114 => 59,  104 => 51,  96 => 48,  358 => 123,  351 => 141,  347 => 140,  343 => 92,  338 => 113,  327 => 102,  323 => 85,  319 => 124,  315 => 98,  301 => 80,  299 => 8,  293 => 90,  289 => 140,  281 => 75,  277 => 136,  271 => 374,  265 => 51,  262 => 81,  260 => 363,  257 => 103,  251 => 101,  248 => 116,  239 => 64,  228 => 41,  225 => 67,  213 => 69,  211 => 81,  197 => 30,  174 => 154,  148 => 69,  134 => 182,  127 => 29,  270 => 84,  253 => 78,  233 => 304,  212 => 60,  210 => 59,  206 => 57,  202 => 55,  198 => 55,  192 => 53,  185 => 61,  180 => 44,  175 => 41,  172 => 51,  167 => 76,  165 => 75,  160 => 39,  137 => 65,  120 => 57,  113 => 55,  100 => 22,  90 => 46,  81 => 47,  65 => 35,  129 => 64,  97 => 52,  84 => 20,  34 => 26,  53 => 10,  37 => 5,  52 => 16,  77 => 25,  74 => 39,  20 => 11,  23 => 4,  480 => 75,  474 => 122,  469 => 158,  461 => 70,  457 => 153,  453 => 151,  444 => 263,  440 => 148,  437 => 61,  435 => 146,  430 => 255,  427 => 143,  423 => 57,  413 => 241,  409 => 132,  407 => 238,  402 => 107,  398 => 88,  393 => 168,  387 => 110,  384 => 106,  381 => 105,  379 => 104,  374 => 128,  368 => 126,  365 => 141,  362 => 148,  360 => 128,  355 => 122,  341 => 131,  337 => 90,  322 => 93,  314 => 88,  312 => 97,  309 => 82,  305 => 115,  298 => 101,  294 => 90,  285 => 78,  283 => 97,  278 => 95,  268 => 373,  264 => 74,  258 => 72,  252 => 68,  247 => 75,  241 => 77,  229 => 73,  220 => 65,  214 => 63,  177 => 43,  169 => 78,  140 => 66,  132 => 65,  128 => 60,  111 => 40,  107 => 52,  61 => 36,  273 => 85,  269 => 133,  254 => 46,  246 => 67,  243 => 66,  240 => 72,  238 => 312,  235 => 63,  230 => 62,  227 => 301,  224 => 39,  221 => 38,  219 => 101,  217 => 64,  208 => 124,  204 => 57,  179 => 84,  159 => 196,  143 => 32,  135 => 51,  131 => 61,  119 => 27,  108 => 23,  102 => 43,  71 => 41,  67 => 20,  63 => 13,  59 => 36,  47 => 11,  38 => 5,  94 => 51,  89 => 28,  85 => 32,  79 => 25,  75 => 43,  68 => 36,  56 => 35,  50 => 29,  29 => 3,  87 => 49,  72 => 18,  55 => 31,  21 => 11,  26 => 12,  98 => 36,  93 => 47,  88 => 33,  78 => 25,  46 => 13,  27 => 5,  40 => 10,  44 => 26,  35 => 8,  31 => 4,  43 => 8,  41 => 7,  28 => 3,  201 => 56,  196 => 52,  183 => 50,  171 => 81,  166 => 38,  163 => 37,  158 => 74,  156 => 38,  151 => 70,  142 => 30,  138 => 69,  136 => 70,  123 => 58,  121 => 61,  117 => 45,  115 => 33,  105 => 55,  101 => 37,  91 => 50,  69 => 40,  66 => 39,  62 => 19,  49 => 15,  24 => 18,  32 => 4,  25 => 3,  22 => 17,  19 => 16,  209 => 58,  203 => 32,  199 => 265,  193 => 51,  189 => 52,  187 => 84,  182 => 85,  176 => 309,  173 => 46,  168 => 80,  164 => 55,  162 => 74,  154 => 71,  149 => 73,  147 => 33,  144 => 26,  141 => 70,  133 => 30,  130 => 57,  125 => 59,  122 => 45,  116 => 43,  112 => 32,  109 => 46,  106 => 30,  103 => 34,  99 => 30,  95 => 51,  92 => 21,  86 => 45,  82 => 33,  80 => 43,  73 => 23,  64 => 38,  60 => 16,  57 => 15,  54 => 34,  51 => 33,  48 => 7,  45 => 30,  42 => 29,  39 => 7,  36 => 7,  33 => 22,  30 => 21,);
    }
}
