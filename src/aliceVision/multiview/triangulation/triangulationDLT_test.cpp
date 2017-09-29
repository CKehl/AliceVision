// This file is part of the AliceVision project and is made available under
// the terms of the MPL2 license (see the COPYING.md file).

#include "aliceVision/multiview/projection.hpp"
#include "aliceVision/multiview/NViewDataSet.hpp"
#include "aliceVision/multiview/triangulation/triangulationDLT.hpp"

#define BOOST_TEST_MODULE triangulationDLT
#include <boost/test/included/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>

using namespace aliceVision;
using namespace std;

BOOST_AUTO_TEST_CASE(Triangulation_TriangulateDLT) {

  NViewDataSet d = NRealisticCamerasRing(2, 12);

  for (int i = 0; i < d._X.cols(); ++i) {
    Vec2 x1, x2;
    x1 = d._x[0].col(i);
    x2 = d._x[1].col(i);
    Vec3 X_estimated, X_gt;
    X_gt = d._X.col(i);
    TriangulateDLT(d.P(0), x1, d.P(1), x2, &X_estimated);
    BOOST_CHECK_SMALL(DistanceLInfinity(X_estimated, X_gt), 1e-8);
  }
}
