$modelname	"tom.mdl"
$body mybody	"tom.smd"
$staticprop
$surfaceprop	combine_metal
$cdmaterials	"tom"

$sequence idle	"tom.smd" // no animation wanted, so re-using the reference mesh

$collisionmodel	"tom.smd" { $concave }