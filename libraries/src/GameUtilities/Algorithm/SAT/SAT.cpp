#include "GameUtilities/Algorithm/SAT/SAT.h"
#include "GameUtilities/Algorithm/SAT/SatObject.h"

namespace GU
{
    namespace Al
    {
        std::pair<float, float> project(const GU::Al::SatObject &first, Math::Vector2<float> normal)
        {
            std::pair<float, float> result(std::numeric_limits<float>::infinity(), -std::numeric_limits<float>::infinity());
            //Find the least and greatest projections of first onto edge
            for(std::size_t i = 0; i < first.getVertexCount(); ++i)
            {
                float dotProduct = normal.dot(first.getGlobalCoordinate(i));
                
                if(dotProduct < result.first)
                    result.first = dotProduct; 

                if(dotProduct > result.second)
                    result.second = dotProduct;
            }
            return result; 
        }
    }
}
