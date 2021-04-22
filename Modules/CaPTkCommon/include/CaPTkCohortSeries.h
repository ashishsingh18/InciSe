/**
contact: software@cbica.upenn.edu
Copyright (c) 2018 University of Pennsylvania. All rights reserved.
Use of this source code is governed by license located in license file:
https://github.com/CBICA/InciSe/blob/main/LICENSE
**/
#ifndef CaPTkCohortSeries_h
#define CaPTkCohortSeries_h

// The following header file is generated by CMake and thus it's located in
// the build directory. It provides an export macro for classes and functions
// that you want to be part of the public interface of your module.
#include <MitkCaPTkCommonExports.h>

namespace captk
{
class CohortImage;
}

#include "mitkImage.h"
#include "mitkLabelSetImage.h"

#include <QString>
#include <QList>
#include <QSharedPointer>

namespace captk
{
/** \class CohortSeries
 * \brief Defines information about a series
 * and holds the series's various images
 * 
 * Note: series is a combination of modality and 
 * acquisition protocol. Multiple series can happen
 * in a study.
 */
class MITKCAPTKCOMMON_EXPORT CohortSeries
{
public:
    CohortSeries();

    ~CohortSeries();

    /* Getters */

    /** Modality (i.e. mri for the series) */
    QString GetModality();

    /** \brief Series description (i.e. t1) for the series */
    QString GetSeriesDescription();

    /** \brief Only application for "seg" modality (segmentation) */
    QString GetSegmentLabel();

    /** \brief Returns a list of all the images in the series 
     * 
     * For nifti and similar, expect only an image per series. 
     * For DICOM, many image files might correspond to a 3D volume.
     * Regardless, a single mitk::Image::Pointer can be obtained 
     * using Load*ImagesAsOne()
    */
    QList<QSharedPointer<CohortImage>> GetImages();

    /** \brief Get a single image for the series
     * 
     * Image files in a series correspond to a single scan,
     * and might represent different slices and similar.
     * With this method a single image can be obtained for series
     */
    mitk::Image::Pointer LoadImagesAsOne();

    /** \brief Get a single label set image for the series
     * 
     * Image files in a series correspond to a single scan,
     * and might represent different slices and similar.
     * With this method a single label set image can be obtained for series
     */
    mitk::LabelSetImage::Pointer LoadSegmentationImagesAsOne();

    /* Setters */

    void SetModality(QString modality);

    void SetSeriesDescription(QString seriesDescription);

    void SetSegmentLabel(QString segmentLabel);

    /** \brief Set the images of series
     * 
     * For nifti and similar that is one file.
     * For DICOM it might be multiple (i.e. one file per slice)
    */
    void SetImages(QList<QSharedPointer<CohortImage>> images);

private:
    QString m_Modality;
    QString m_SeriesDescription;
    QString m_SegmentLabel;
    QList<QSharedPointer<CohortImage>> m_Images;
};
}

#endif // ! CaPTkCohortSeries_h