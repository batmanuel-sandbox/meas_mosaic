// -*- lsst-c++ -*-
#ifndef MEAS_MOSAIC_fluxfit_h_INCLUDED
#define MEAS_MOSAIC_fluxfit_h_INCLUDED

#include "lsst/meas/mosaic/mosaicfit.h"

namespace lsst {
    namespace meas {
	namespace mosaic {

	    class FluxFitParams {
	    public:
		typedef boost::shared_ptr<FluxFitParams> Ptr;

		int order;
		bool chebyshev;
		int ncoeff;
		int *xorder;
		int *yorder;
		bool absolute;

		double *coeff;
		double u_max;
		double v_max;
		double x0;
		double y0;

		FluxFitParams(int order, bool absolute=false, bool chebyshev=false);
		FluxFitParams(lsst::daf::base::PropertySet::Ptr& metadata);
		~FluxFitParams();
		FluxFitParams(const FluxFitParams &p);
		double eval(double u, double v);
		int getXorder(int i) { return xorder[i]; }
		int getYorder(int i) { return yorder[i]; }
		double getCoeff(int i) { return coeff[i]; }
		int getIndex(int i, int j);
	    };

	    typedef std::map<int, FluxFitParams::Ptr> FfpSet;

	    void fluxFit(bool absolute,
			 bool common,
			 ObsVec& matchVec,
			 int nmatch,
			 ObsVec& sourceVec,
			 int nsource,
			 WcsDic& wcsDic,
			 CcdSet& ccdSet,
			 std::map<int, float>& fexp,
			 std::map<int, float>& fchip,
			 FfpSet &ffpSet,
			 bool solveCcd);

	    FluxFitParams::Ptr
	      convertFluxFitParams(FluxFitParams::Ptr& ffp,
				   lsst::afw::cameraGeom::Ccd::Ptr& ccd,
				   double x0=0.0, double y0=0.0);

	    lsst::daf::base::PropertySet::Ptr
	      metadataFromFluxFitParams(FluxFitParams::Ptr& ffp);

	    lsst::afw::image::Image<float>::Ptr
	      getFCorImg(FluxFitParams::Ptr& p,
			 lsst::afw::cameraGeom::Ccd::Ptr& ccd,
			 Coeff::Ptr& coeff);

	    lsst::afw::image::Image<float>::Ptr
	      getFCorImg(FluxFitParams::Ptr& p, int width, int height);

	    lsst::afw::image::Image<float>::Ptr
	      getFCorImg(FluxFitParams::Ptr& p,
			 lsst::afw::cameraGeom::Ccd::Ptr& ccd);

#include "chebyshev.h"
    }
  }
}

#endif