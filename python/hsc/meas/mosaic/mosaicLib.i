// -*- lsst-c++ -*-
%define fitLib_DOCSTRING
"
Python interface to hsc::meas::fit
"
%enddef

%feature("autodoc", "1");
%module(package="hsc.meas.mosaic", docstring=fitLib_DOCSTRING) mosaicLib

%{
#include "lsst/afw/image.h"
%}

%include "lsst/p_lsstSwig.i"

%pythoncode %{
import lsst.utils

def version(HeadURL = r"$HeadURL: ssh://hsc-gw2.mtk.nao.ac.jp/ana/hgrepo/hscMosaic/python/hsc/meas/mosaic/mosaicLib.i $"):
    version_svn = lsst.utils.guessSvnVersion(HeadURL)

    try:
	import eups
    except ImportError:
        return version_svn
    else:
	try:
	    version_eups = eups.setup("hscMosaic")
	except AttributeError:
	    return version_svn

    if version_eups == version_svn:
        return version_svn
    else:
	return "%s (setup: %s)" % (version_svn, version_eups)
%}

%import "lsst/afw/image/imageLib.i"
%import "lsst/afw/geom/geomLib.i"
%import "lsst/afw/detection/detectionLib.i"

%include "mosaic.i"