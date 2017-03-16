#include "primitivelib_global.h"
#include "primitive.h"
#include "tankprimitive.h"
#include "fireprimitive.h"
#include "horizontalpipeprimitive.h"
#include "teeprimitive.h"
#include "verticalprimitive.h"
#include "curveprimitive.h"
#include "buildingprimitive.h"
#include "elevatedtankprimitive.h"
#include "palmtreeprimitive.h"
#include "textprimitive.h"
#include "linechartprimitive.h"

extern "C" MY_EXPORT Primitive* getTankPrimitive(QWidget *parent)
{
    return new TankPrimitive(parent);
}

extern "C" MY_EXPORT Primitive* getFirePrimitive(QWidget *parent)
{
    return new FirePrimitive(parent);
}

extern "C" MY_EXPORT Primitive* getHorizontalPipePrimitive(QWidget *parent)
{
    return new HorizontalPipePrimitive(parent);
}

extern "C" MY_EXPORT Primitive* getTeePrimitive(QWidget *parent)
{
    return new TeePrimitive(parent);
}

extern "C" MY_EXPORT Primitive* getVerticalPrimitive(QWidget *parent)
{
    return new VerticalPrimitive(parent);
}

extern "C" MY_EXPORT Primitive* getCurvePrimitive(QWidget *parent)
{
    return new CurvePrimitive(parent);
}

extern "C" MY_EXPORT Primitive* getBuildingPrimitive(QWidget *parent)
{
    return new BuildingPrimitive(parent);
}

extern "C" MY_EXPORT Primitive* getElevatedTankPrimitive(QWidget *parent)
{
    return new ElevatedTankPrimitive(parent);
}

extern "C" MY_EXPORT Primitive* getPalmTreePrimitive(QWidget *parent)
{
    return new PalmTreePrimitive(parent);
}

extern "C" MY_EXPORT Primitive* getTextPrimitive(QWidget *parent)
{
    return new TextPrimitive(parent);
}

extern "C" MY_EXPORT Primitive* getLineChartPrimitive(QWidget *parent)
{
    return new LineChartPrimitive(parent);
}
