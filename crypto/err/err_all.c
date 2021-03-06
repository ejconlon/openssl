/*
 * Copyright 1995-2016 The OpenSSL Project Authors. All Rights Reserved.
 *
 * Licensed under the OpenSSL license (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://www.openssl.org/source/license.html
 */

#include <stdio.h>
#include "internal/err_int.h"
#include <openssl/asn1.h>
#include <openssl/bn.h>
#include <openssl/ec.h>
#include <openssl/buffer.h>
#include <openssl/bio.h>
#include <openssl/comp.h>
#include <openssl/rsa.h>
#include <openssl/dh.h>
#include <openssl/dsa.h>
#include <openssl/evp.h>
#include <openssl/objects.h>
#include <openssl/pem2.h>
#include <openssl/x509.h>
#include <openssl/x509v3.h>
#include <openssl/conf.h>
#include <openssl/pkcs12.h>
#include <openssl/rand.h>
#include "internal/dso.h"
#include <openssl/engine.h>
#include <openssl/ui.h>
#include <openssl/ocsp.h>
#include <openssl/err.h>
#ifdef OPENSSL_FIPS
# include <openssl/fips.h>
#endif
#include <openssl/ts.h>
#include <openssl/cms.h>
#include <openssl/ct.h>
#include <openssl/async.h>
#include <openssl/kdf.h>

void err_load_crypto_strings_int(void)
{
#ifdef OPENSSL_FIPS
    FIPS_set_error_callbacks(ERR_put_error, ERR_add_error_vdata);
#endif
#ifndef OPENSSL_NO_ERR
    ERR_load_ERR_strings();     /* include error strings for SYSerr */
    ERR_load_BN_strings();
# ifndef OPENSSL_NO_RSA
    ERR_load_RSA_strings();
# endif
# ifndef OPENSSL_NO_DH
    ERR_load_DH_strings();
# endif
    ERR_load_EVP_strings();
    ERR_load_BUF_strings();
    ERR_load_OBJ_strings();
    ERR_load_PEM_strings();
# ifndef OPENSSL_NO_DSA
    ERR_load_DSA_strings();
# endif
    ERR_load_X509_strings();
    ERR_load_ASN1_strings();
    ERR_load_CONF_strings();
    ERR_load_CRYPTO_strings();
# ifndef OPENSSL_NO_COMP
    ERR_load_COMP_strings();
# endif
# ifndef OPENSSL_NO_EC
    ERR_load_EC_strings();
# endif
    /* skip ERR_load_SSL_strings() because it is not in this library */
    ERR_load_BIO_strings();
    ERR_load_PKCS7_strings();
    ERR_load_X509V3_strings();
    ERR_load_PKCS12_strings();
    ERR_load_RAND_strings();
    ERR_load_DSO_strings();
# ifndef OPENSSL_NO_TS
    ERR_load_TS_strings();
# endif
# ifndef OPENSSL_NO_ENGINE
    ERR_load_ENGINE_strings();
# endif
# ifndef OPENSSL_NO_OCSP
    ERR_load_OCSP_strings();
# endif
#ifndef OPENSSL_NO_UI
    ERR_load_UI_strings();
#endif
# ifdef OPENSSL_FIPS
    ERR_load_FIPS_strings();
# endif
# ifndef OPENSSL_NO_CMS
    ERR_load_CMS_strings();
# endif
# ifndef OPENSSL_NO_CT
    ERR_load_CT_strings();
# endif
    ERR_load_ASYNC_strings();
#endif
    ERR_load_KDF_strings();
}
