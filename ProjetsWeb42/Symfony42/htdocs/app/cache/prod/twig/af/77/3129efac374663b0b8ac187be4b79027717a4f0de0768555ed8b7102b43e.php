<?php

/* SonataDoctrineORMAdminBundle:CRUD:edit_orm_one_association_script.html.twig */
class __TwigTemplate_af773129efac374663b0b8ac187be4b79027717a4f0de0768555ed8b7102b43e extends Twig_Template
{
    public function __construct(Twig_Environment $env)
    {
        parent::__construct($env);

        $this->parent = false;

        $this->blocks = array(
        );
    }

    protected function doDisplay(array $context, array $blocks = array())
    {
        // line 11
        echo "

";
        // line 18
        echo "
";
        // line 20
        echo "
<!-- edit one association -->

<script type=\"text/javascript\">

    // handle the add link
    var field_add_";
        // line 26
        echo (isset($context["id"]) ? $context["id"] : null);
        echo " = function(event) {

        event.preventDefault();
        event.stopPropagation();

        var form = jQuery(this).closest('form');

        // the ajax post
        jQuery(form).ajaxSubmit({
            url: '";
        // line 35
        echo $this->env->getExtension('routing')->getUrl("sonata_admin_append_form_element", (array("code" => $this->getAttribute($this->getAttribute($this->getAttribute((isset($context["sonata_admin"]) ? $context["sonata_admin"] : null), "admin"), "root"), "code"), "elementId" => (isset($context["id"]) ? $context["id"] : null), "objectId" => $this->getAttribute($this->getAttribute($this->getAttribute((isset($context["sonata_admin"]) ? $context["sonata_admin"] : null), "admin"), "root"), "id", array(0 => $this->getAttribute($this->getAttribute($this->getAttribute((isset($context["sonata_admin"]) ? $context["sonata_admin"] : null), "admin"), "root"), "subject")), "method"), "uniqid" => $this->getAttribute($this->getAttribute($this->getAttribute((isset($context["sonata_admin"]) ? $context["sonata_admin"] : null), "admin"), "root"), "uniqid")) + $this->getAttribute($this->getAttribute((isset($context["sonata_admin"]) ? $context["sonata_admin"] : null), "field_description"), "getOption", array(0 => "link_parameters", 1 => array()), "method")));
        // line 40
        echo "',
            type: \"POST\",
            dataType: 'html',
            data: { _xml_http_request: true },
            success: function(html) {
                if (!html.length) {
                    return;
                }

                jQuery('#field_container_";
        // line 49
        echo (isset($context["id"]) ? $context["id"] : null);
        echo "').replaceWith(html); // replace the html

                Admin.shared_setup(jQuery('#field_container_";
        // line 51
        echo (isset($context["id"]) ? $context["id"] : null);
        echo "'));

                if(jQuery('input[type=\"file\"]', form).length > 0) {
                    jQuery(form).attr('enctype', 'multipart/form-data');
                    jQuery(form).attr('encoding', 'multipart/form-data');
                }
                jQuery('#sonata-ba-field-container-";
        // line 57
        echo (isset($context["id"]) ? $context["id"] : null);
        echo "').trigger('sonata.add_element');
                jQuery('#field_container_";
        // line 58
        echo (isset($context["id"]) ? $context["id"] : null);
        echo "').trigger('sonata.add_element');
            }
        });

        return false;
    };

    var field_widget_";
        // line 65
        echo (isset($context["id"]) ? $context["id"] : null);
        echo " = false;

    // this function initialize the popup
    // this can be only done this way has popup can be cascaded
    function start_field_retrieve_";
        // line 69
        echo (isset($context["id"]) ? $context["id"] : null);
        echo "(link) {

        link.onclick = null;

        // initialize component
        field_widget_";
        // line 74
        echo (isset($context["id"]) ? $context["id"] : null);
        echo " = jQuery(\"#field_widget_";
        echo (isset($context["id"]) ? $context["id"] : null);
        echo "\");

        // add the jQuery event to the a element
        jQuery(link)
            .click(field_add_";
        // line 78
        echo (isset($context["id"]) ? $context["id"] : null);
        echo ")
            .trigger('click')
        ;

        return false;
    }
</script>

<!-- / edit one association -->

";
    }

    public function getTemplateName()
    {
        return "SonataDoctrineORMAdminBundle:CRUD:edit_orm_one_association_script.html.twig";
    }

    public function isTraitable()
    {
        return false;
    }

    public function getDebugInfo()
    {
        return array (  188 => 84,  181 => 80,  161 => 71,  320 => 122,  317 => 121,  311 => 118,  288 => 107,  284 => 106,  279 => 104,  275 => 103,  256 => 96,  250 => 93,  237 => 86,  232 => 84,  222 => 81,  191 => 69,  153 => 56,  150 => 55,  145 => 52,  110 => 48,  692 => 399,  683 => 393,  678 => 390,  676 => 385,  666 => 382,  661 => 380,  656 => 378,  652 => 376,  645 => 369,  641 => 368,  635 => 365,  631 => 364,  625 => 361,  615 => 354,  607 => 349,  597 => 342,  590 => 338,  583 => 334,  579 => 332,  577 => 329,  575 => 328,  569 => 325,  565 => 324,  555 => 317,  548 => 313,  540 => 308,  536 => 306,  529 => 299,  524 => 297,  516 => 294,  510 => 293,  504 => 292,  500 => 291,  495 => 289,  490 => 287,  486 => 286,  482 => 285,  470 => 278,  464 => 275,  459 => 273,  452 => 268,  434 => 256,  421 => 244,  417 => 243,  400 => 233,  385 => 225,  361 => 207,  344 => 193,  339 => 191,  324 => 179,  310 => 171,  302 => 168,  296 => 167,  282 => 161,  259 => 149,  244 => 140,  231 => 133,  226 => 131,  215 => 78,  186 => 83,  152 => 92,  114 => 71,  104 => 67,  96 => 37,  358 => 139,  351 => 135,  347 => 134,  343 => 132,  338 => 130,  327 => 126,  323 => 125,  319 => 124,  315 => 120,  301 => 117,  299 => 112,  293 => 109,  289 => 163,  281 => 105,  277 => 109,  271 => 108,  265 => 99,  262 => 105,  260 => 98,  257 => 103,  251 => 101,  248 => 100,  239 => 97,  228 => 83,  225 => 87,  213 => 82,  211 => 81,  197 => 70,  174 => 64,  148 => 64,  134 => 47,  127 => 56,  270 => 157,  253 => 95,  233 => 81,  212 => 74,  210 => 75,  206 => 71,  202 => 77,  198 => 66,  192 => 86,  185 => 68,  180 => 56,  175 => 77,  172 => 51,  167 => 48,  165 => 59,  160 => 58,  137 => 59,  120 => 36,  113 => 41,  100 => 36,  90 => 20,  81 => 15,  65 => 30,  129 => 59,  97 => 63,  84 => 39,  34 => 26,  53 => 10,  37 => 19,  52 => 21,  77 => 58,  74 => 34,  20 => 11,  23 => 18,  480 => 162,  474 => 161,  469 => 158,  461 => 155,  457 => 153,  453 => 151,  444 => 263,  440 => 148,  437 => 147,  435 => 146,  430 => 255,  427 => 143,  423 => 250,  413 => 241,  409 => 132,  407 => 238,  402 => 237,  398 => 232,  393 => 230,  387 => 122,  384 => 121,  381 => 120,  379 => 119,  374 => 217,  368 => 112,  365 => 141,  362 => 110,  360 => 109,  355 => 106,  341 => 131,  337 => 103,  322 => 101,  314 => 99,  312 => 98,  309 => 117,  305 => 115,  298 => 91,  294 => 90,  285 => 111,  283 => 88,  278 => 160,  268 => 107,  264 => 2,  258 => 81,  252 => 80,  247 => 78,  241 => 77,  229 => 73,  220 => 80,  214 => 69,  177 => 54,  169 => 74,  140 => 55,  132 => 58,  128 => 49,  111 => 78,  107 => 52,  61 => 25,  273 => 96,  269 => 100,  254 => 147,  246 => 99,  243 => 89,  240 => 139,  238 => 85,  235 => 74,  230 => 82,  227 => 81,  224 => 71,  221 => 79,  219 => 84,  217 => 79,  208 => 124,  204 => 73,  179 => 66,  159 => 70,  143 => 59,  135 => 81,  131 => 48,  119 => 43,  108 => 39,  102 => 74,  71 => 28,  67 => 28,  63 => 15,  59 => 49,  47 => 21,  38 => 17,  94 => 69,  89 => 40,  85 => 34,  79 => 37,  75 => 17,  68 => 31,  56 => 24,  50 => 20,  29 => 21,  87 => 65,  72 => 10,  55 => 79,  21 => 12,  26 => 20,  98 => 44,  93 => 21,  88 => 60,  78 => 36,  46 => 35,  27 => 8,  40 => 20,  44 => 18,  35 => 16,  31 => 22,  43 => 20,  41 => 18,  28 => 13,  201 => 72,  196 => 65,  183 => 82,  171 => 63,  166 => 100,  163 => 45,  158 => 62,  156 => 57,  151 => 63,  142 => 61,  138 => 50,  136 => 56,  123 => 47,  121 => 53,  117 => 34,  115 => 50,  105 => 47,  101 => 49,  91 => 34,  69 => 50,  66 => 29,  62 => 29,  49 => 9,  24 => 13,  32 => 15,  25 => 12,  22 => 12,  19 => 11,  209 => 82,  203 => 122,  199 => 67,  193 => 73,  189 => 71,  187 => 60,  182 => 69,  176 => 65,  173 => 65,  168 => 60,  164 => 72,  162 => 59,  154 => 67,  149 => 51,  147 => 90,  144 => 49,  141 => 48,  133 => 55,  130 => 57,  125 => 45,  122 => 44,  116 => 42,  112 => 42,  109 => 69,  106 => 33,  103 => 46,  99 => 38,  95 => 43,  92 => 61,  86 => 17,  82 => 33,  80 => 19,  73 => 57,  64 => 51,  60 => 15,  57 => 22,  54 => 10,  51 => 38,  48 => 40,  45 => 19,  42 => 7,  39 => 17,  36 => 17,  33 => 4,  30 => 15,);
    }
}
